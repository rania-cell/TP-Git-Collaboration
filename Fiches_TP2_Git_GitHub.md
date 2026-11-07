# TP N° 2 – Git et GitHub
## Collaboration, fusion et sécurité

**Module :** DevOps  
**Thème :** Gestion des dépôts, collaboration, fusion et sécurité avec Git et GitHub.

---

# Sommaire

- Partie A : Création du dépôt et configuration de Git
- Partie B : Développement collaboratif avec les branches
- Partie D : Provoquer et résoudre un conflit de fusion
- Partie E : Authentification SSH et clés cryptographiques
- Partie F : Ignorer certains fichiers avec `.gitignore`
- Partie G : Notions avancées de Git
- Conclusion

---

# PARTIE A – Création du dépôt et configuration de Git

### Question A : Quelle est la différence entre un dépôt local et un dépôt distant ?

Un **dépôt local** est un dépôt Git stocké sur l'ordinateur de l'utilisateur. Il permet de créer, modifier et enregistrer les fichiers du projet à l'aide des commits.

Un **dépôt distant** est un dépôt hébergé sur un serveur externe, comme GitHub. Il permet de partager le projet, de sauvegarder les modifications et de collaborer avec d'autres développeurs.

**Exemple :**

```bash
git commit -m "Ajout du module"
git push origin main
```

La commande `git commit` enregistre les modifications dans le dépôt local, tandis que `git push` permet de transmettre les commits au dépôt distant.

---

# PARTIE B – Développement collaboratif avec les branches

### Question B1 : Quel est l'intérêt d'une branche par fonctionnalité ?

Une branche par fonctionnalité permet de développer une partie spécifique du projet indépendamment des autres modifications, sans affecter directement la branche principale `main`.

Cette organisation facilite le travail collaboratif, permet à chaque développeur de travailler sur une tâche précise et réduit les risques d'interférence entre les modifications.

**Exemple d'organisation des branches :**

| Branche | Fonctionnalité |
|---|---|
| `feature/module1` | Saisie et vérification du mot de passe |
| `feature/module2` | Analyse de la robustesse du mot de passe |
| `feature/module3` | Affichage des résultats et du rapport de sécurité |
| `feature/integration` | Intégration et tests du projet |

### Question B2 : À quoi sert un commit ?

Un **commit** permet d'enregistrer un ensemble de modifications dans l'historique du dépôt local.

Chaque commit possède un identifiant unique appelé `Hash`, ainsi qu'un message descriptif permettant d'identifier les modifications effectuées.

**Exemple :**

```bash
git add module2.c
git commit -m "Ajout du module d'analyse de securite"
```

La commande `git add` ajoute les fichiers modifiés à la zone de préparation (*Staging Area*), tandis que `git commit` enregistre ces modifications dans l'historique du projet.

### Question B3 : Quelle est la différence entre push et pull ?

La commande `git push` permet d'envoyer les commits locaux vers le dépôt distant afin de partager les modifications avec les autres collaborateurs.

La commande `git pull` permet de récupérer les modifications du dépôt distant et de les intégrer dans la branche locale courante.

**Exemples :**

```bash
git push origin feature/module2
```

Cette commande envoie les modifications de la branche `feature/module2` vers GitHub.

```bash
git pull origin main
```

Cette commande récupère et intègre les dernières modifications de la branche distante `main`.

### Question B4 : Quel est le rôle d'une Pull Request ?

Une **Pull Request (PR)** est une demande d'intégration des modifications d'une branche dans une autre branche, généralement `main`.

Elle permet aux membres de l'équipe de :

- Examiner les modifications du code (*Code Review*).
- Discuter des changements proposés.
- Identifier et corriger les erreurs.
- Vérifier la qualité du code avant son intégration.

La Pull Request constitue donc un mécanisme essentiel pour organiser et contrôler le développement collaboratif.

---

# PARTIE D – Provoquer et résoudre un conflit de fusion

### Question D1 : Pourquoi Git ne peut-il pas choisir automatiquement entre les deux versions ?

Git ne peut pas choisir automatiquement entre deux versions lorsque plusieurs développeurs modifient la même ligne d'un fichier de manière différente.

Dans cette situation, Git ne peut pas déterminer quelle modification doit être conservée. Une intervention humaine est donc nécessaire pour comparer les versions et résoudre le conflit.

**Exemple :**

Version A :

```c
printf("Application developpee par A\n");
```

Version B :

```c
printf("Application developpee par B\n");
```

Les deux versions modifient la même ligne avec des contenus différents, ce qui provoque un conflit de fusion (*Merge Conflict*).

### Question D2 : Que représentent les marqueurs de conflit ?

Les marqueurs de conflit sont des indications insérées automatiquement par Git dans un fichier lorsqu'un conflit de fusion est détecté.

**Exemple :**

```text
<<<<<<< HEAD
printf("Application developpee par B\n");
=======
printf("Application developpee par A\n");
>>>>>>> origin/main
```

Leur signification est la suivante :

- `<<<<<<< HEAD` : indique le début de la version présente dans la branche courante.
- `=======` : sépare les deux versions en conflit.
- `>>>>>>> origin/main` : indique la fin de la version provenant de la branche entrante.

Ces marqueurs doivent être supprimés après avoir choisi ou combiné les modifications souhaitées.

### Question D3 : Quelle est la différence entre résoudre un conflit et annuler une modification ?

**Résoudre un conflit** consiste à examiner les modifications contradictoires, puis à choisir la version appropriée ou à combiner les deux modifications afin d'obtenir une version cohérente du fichier.

**Annuler une modification** consiste à supprimer ou abandonner un changement effectué précédemment.

Ainsi, la résolution d'un conflit vise à conserver une version correcte du projet, tandis que l'annulation consiste à revenir sur une modification antérieure.

### Question D4 : Pourquoi faut-il tester le programme après une fusion ?

Il est nécessaire de tester le programme après une fusion afin de vérifier que les modifications intégrées ne provoquent pas d'erreurs de compilation ou d'exécution.

Une fusion incorrecte peut entraîner la suppression de certaines instructions, des problèmes de compatibilité entre les modules ou des erreurs dans le fonctionnement général du programme.

La compilation et l'exécution permettent donc de vérifier que l'ensemble des modifications fonctionne correctement.

---

# PARTIE E – Authentification SSH et clés cryptographiques

### Question E1 : Expliquez la différence entre une clé publique et une clé privée.

L'authentification SSH repose sur une paire de clés cryptographiques :

- **Clé publique :** elle peut être partagée et ajoutée au compte GitHub. Elle intervient dans le processus de vérification de l'identité.
- **Clé privée :** elle doit rester confidentielle et être conservée sur l'ordinateur de son propriétaire. Elle ne doit jamais être partagée.

Ces deux clés sont utilisées conjointement dans le mécanisme d'authentification SSH afin de sécuriser la connexion entre l'utilisateur et le serveur distant.

### Question E2 : Pourquoi chaque étudiant doit-il disposer de sa propre paire de clés ?

Chaque étudiant doit disposer de sa propre paire de clés afin de garantir une authentification individuelle.

Cette pratique permet :

- D'identifier chaque utilisateur de manière distincte.
- De renforcer la sécurité du dépôt.
- De contrôler les accès individuels.
- De limiter les risques en cas de compromission d'une clé.

L'utilisation de clés personnelles évite également le partage d'identifiants entre les membres de l'équipe.

### Question E3 : Quel est le rôle de la phrase secrète protégeant la clé privée ?

La phrase secrète (*Passphrase*) constitue une protection supplémentaire de la clé privée.

Elle permet de limiter l'utilisation de cette clé par une personne non autorisée qui aurait accès au fichier correspondant.

Ainsi, même si le fichier contenant la clé privée est récupéré, la passphrase ajoute une barrière de sécurité contre son utilisation frauduleuse.

### Question E4 : Quelle est la différence entre l'authentification SSH et la signature cryptographique d'un commit ?

L'**authentification SSH** permet de vérifier l'identité de l'utilisateur lors de sa connexion à GitHub et de sécuriser les échanges avec le dépôt distant. Elle permet notamment d'effectuer des opérations telles que `push` et `pull`.

La **signature cryptographique d'un commit** permet de vérifier l'authenticité d'un commit en confirmant qu'il a été signé à l'aide d'une clé reconnue. Elle permet également de vérifier l'intégrité de la signature.

En résumé, l'authentification SSH sécurise l'accès au dépôt distant, tandis que la signature cryptographique permet de vérifier l'origine et l'authenticité des commits.

### Question E5 : Pourquoi ne faut-il jamais publier une clé privée dans un dépôt Git ?

Une clé privée constitue une information confidentielle qui ne doit jamais être publiée dans un dépôt Git.

Sa divulgation pourrait permettre à une personne malveillante d'usurper l'identité de son propriétaire et d'accéder aux ressources protégées par cette clé.

Il est donc indispensable de conserver la clé privée dans un environnement sécurisé et de ne partager que la clé publique.

---

# PARTIE F – Ignorer certains fichiers avec .gitignore

### Question F1 : Quelle est la différence entre un fichier ignoré et un fichier déjà suivi par Git ?

Un **fichier ignoré** est un fichier correspondant à une règle définie dans le fichier `.gitignore`. Git ne propose généralement pas ce fichier pour le suivi lorsqu'il n'est pas déjà suivi.

Un **fichier déjà suivi** est un fichier qui a été précédemment ajouté au dépôt Git et qui fait partie des fichiers suivis par le système de gestion de versions.

Il est important de noter que l'ajout d'un fichier déjà suivi dans `.gitignore` ne suffit pas à arrêter son suivi.

### Question F2 : À quoi sert la commande git check-ignore -v ?

La commande `git check-ignore -v` permet d'identifier la règle responsable de l'exclusion d'un fichier par Git.

Elle affiche notamment le fichier `.gitignore` concerné, le numéro de ligne et la règle qui provoque l'ignorance du fichier.

**Exemple :**

```bash
git check-ignore -v test.tmp
```

Cette commande permet de déterminer pourquoi le fichier `test.tmp` est ignoré par Git.

### Question F3 : Pourquoi faut-il vérifier git status avant un commit ?

La commande `git status` permet de vérifier l'état du dépôt avant d'effectuer un commit.

Elle indique les fichiers modifiés, ajoutés, supprimés ou non suivis.

Cette vérification permet de contrôler les modifications qui seront enregistrées et d'éviter l'ajout accidentel de fichiers inutiles ou contenant des informations sensibles.

**Exemple :**

```bash
git status
```

### Question F4 : Pourquoi un fichier .env contenant des secrets ne doit-il pas être publié ?

Un fichier `.env` peut contenir des informations sensibles telles que :

- Des mots de passe.
- Des clés API.
- Des identifiants de connexion.
- Des informations relatives aux bases de données.

La publication de ce fichier sur GitHub pourrait exposer ces informations à des personnes non autorisées et entraîner des risques de compromission.

Il est donc recommandé d'ajouter le fichier `.env` dans `.gitignore` afin d'éviter son ajout accidentel au dépôt.

---

# PARTIE G – Notions avancées de Git

### Question G1 : Quelle est la différence entre reset --soft, --mixed et --hard ?

Les commandes `git reset --soft`, `git reset --mixed` et `git reset --hard` permettent de déplacer la référence de la branche vers un commit précédent. Elles se distinguent par leur manière de gérer l'index (*Staging Area*) et les fichiers de travail.

| Commande | Historique | Staging Area | Fichiers de travail |
|---|---|---|---|
| `--soft` | Modifié | Modifications conservées | Modifications conservées |
| `--mixed` | Modifié | Index réinitialisé | Modifications conservées |
| `--hard` | Modifié | Index réinitialisé | Modifications supprimées |

**1. Reset --soft**

```bash
git reset --soft HEAD~1
```

Cette commande annule le dernier commit tout en conservant les modifications dans la Staging Area.

**2. Reset --mixed**

```bash
git reset --mixed HEAD~1
```

Cette commande annule le dernier commit et retire les modifications de la Staging Area, tout en les conservant dans les fichiers de travail.

**3. Reset --hard**

```bash
git reset --hard HEAD~1
```

Cette commande annule le dernier commit et réinitialise également l'index et les fichiers de travail.

**Attention :** la commande `git reset --hard` peut entraîner la perte définitive des modifications locales non sauvegardées.

### Question G2 : Pourquoi préférer git revert à git reset pour un commit déjà publié ?

Il est préférable d'utiliser `git revert` pour annuler un commit déjà publié sur un dépôt distant.

En effet, cette commande crée un nouveau commit qui inverse les modifications du commit précédent, sans supprimer ni réécrire l'historique existant.

En revanche, `git reset` peut modifier l'historique de la branche et provoquer des problèmes de synchronisation avec les autres collaborateurs.

**Exemple :**

```bash
git revert <commit-hash>
```

Cette commande permet d'annuler les modifications d'un commit tout en conservant l'historique du projet.

### Question G3 : Quelle est la différence entre un fork et un clone ? Et entre un fork et une branche ?

**Fork :**

Un fork est une copie indépendante d'un dépôt GitHub créée sur le compte personnel d'un autre utilisateur. Il permet de travailler sur une version distincte du projet original.

**Clone :**

Un clone est une copie locale d'un dépôt distant téléchargée sur l'ordinateur de l'utilisateur. Il permet de travailler localement sur le projet.

**Branche :**

Une branche représente une ligne de développement indépendante à l'intérieur d'un même dépôt. Elle permet de développer une fonctionnalité sans modifier directement la branche principale.

En résumé, un fork crée une copie indépendante sur GitHub, un clone crée une copie locale et une branche permet de séparer les différentes fonctionnalités au sein d'un même dépôt.

### Question G4 : À quoi sert le dépôt distant upstream ?

Le dépôt distant `upstream` désigne généralement le dépôt original à partir duquel un fork a été créé.

Il permet de récupérer les modifications effectuées dans le dépôt original afin de maintenir le fork à jour.

**Exemple :**

```bash
git remote add upstream https://github.com/UTILISATEUR/TP-Git-Collaboration.git
```

Pour récupérer les dernières modifications :

```bash
git fetch upstream
```

Cette opération permet de télécharger les nouvelles références du dépôt original sans les fusionner automatiquement dans la branche locale.

### Question G5 : Que se passe-t-il lorsqu'on supprime une branche locale : la branche distante est-elle supprimée aussi ?

La suppression d'une branche locale n'entraîne pas automatiquement la suppression de la branche distante.

Les branches locales et distantes sont indépendantes et doivent être supprimées séparément.

**Supprimer une branche locale :**

```bash
git branch -d feature/test1
```

**Supprimer une branche distante :**

```bash
git push origin --delete feature/test1
```

Ainsi, la suppression d'une branche sur l'ordinateur n'affecte pas automatiquement son équivalent sur GitHub.

### Question G6 : Quand un fast-forward est-il possible ? Pourquoi utiliser --no-ff ?

Un **Fast-forward** est possible lorsque la branche cible n'a pas reçu de nouveaux commits depuis la création de la branche à fusionner.

Dans cette situation, Git peut déplacer directement le pointeur de la branche cible vers le dernier commit de la branche entrante, sans créer de commit de fusion.

L'option `--no-ff` permet de forcer la création d'un *Merge Commit*, même lorsqu'un fast-forward est possible.

Elle est utilisée pour conserver une trace explicite de l'intégration d'une branche dans l'historique du projet.

**Exemple :**

```bash
git merge --no-ff feature/module1
```

### Question G7 : Quels sont les avantages et les risques du rebase par rapport au merge ?

**1. Le Rebase**

Avantages :
- Permet d'obtenir un historique plus linéaire et plus facile à lire.
- Facilite l'organisation de l'historique des commits.
- Permet d'intégrer les dernières modifications de la branche cible.

Risques :
- Réécrit l'historique des commits.
- Peut provoquer des problèmes de synchronisation lorsqu'il est utilisé sur une branche partagée.
- Peut entraîner des conflits qui doivent être résolus pendant l'opération.

**2. Le Merge**

Avantages :
- Conserve l'historique original des branches.
- Permet de visualiser clairement les opérations de fusion.
- Convient particulièrement au travail collaboratif sur des branches partagées.

Inconvénients :
- Peut rendre l'historique du projet plus complexe, notamment lorsque les opérations de fusion sont nombreuses.

**Conclusion :**

Il est généralement préférable d'utiliser `rebase` sur une branche personnelle non partagée et `merge` pour intégrer les modifications dans les branches communes.

---

# CONCLUSION GÉNÉRALE

Ce TP a permis d'étudier les principales fonctionnalités de Git et GitHub dans un environnement de développement collaboratif.

Les différentes parties ont abordé la gestion des dépôts locaux et distants, l'utilisation des branches, le suivi des modifications avec les commits, ainsi que le partage du code à travers les Pull Requests.

Le TP a également permis de comprendre la gestion des conflits de fusion, les mécanismes d'authentification SSH et les bonnes pratiques de sécurité liées à la protection des clés privées et à l'utilisation du fichier `.gitignore`.

Enfin, les commandes avancées telles que `reset`, `revert`, `merge` et `rebase` permettent de mieux maîtriser l'historique du projet et de faciliter la collaboration entre les développeurs.

---

# RÉCAPITULATIF DES QUESTIONS

| Partie | Nombre de questions | Thème principal |
|---|---:|---|
| A | 1 | Dépôt local et dépôt distant |
| B | 4 | Branches, commits, push, pull et Pull Requests |
| D | 4 | Conflits et résolution |
| E | 5 | Authentification SSH et clés cryptographiques |
| F | 4 | `.gitignore` et sécurité |
| G | 7 | Reset, revert, fork, upstream, merge et rebase |
| **Total** | **25** | **Questions théoriques** |

**Remarque :** la Partie C est consacrée à une activité pratique concernant les notifications et ne contient pas de question théorique dans les éléments étudiés pour cette fiche.
