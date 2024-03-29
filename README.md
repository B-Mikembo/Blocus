# Blocus
 Le terrain de jeu prend la forme d'une grille carrée dont la taille sera choisie à chaque partie entre 3 et 9. L'un après l'autre les deux joueurs choisissent une case où placer leur pion (les deux pions ne peuvent pas partager la même case).

Une fois le terrain mis en place, les joueurs alternent les tours. Durant le tour d'un joueur, il doit déplacer son pion vers une case adjacente (y compris en diagonale), puis choisir une case libre qui sera condamnée. Le premier joueur qui ne peut pas déplacer son pion (car toutes les cases adjacentes sont condamnées ou occupées) a perdu.

L'interface du jeu sera contrôlée entièrement à la souris et consistera en trois écrans. Le premier écran proposera de choisir la taille du terrain de jeu, et de démarrer une partie à un ou deux joueurs. Le deuxième écran permet de jouer la partie. Le troisième écran affiche le gagnant et permet de choisir entre terminer le programme et lancer une nouvelle partie.

Dans une partie à un seul joueur, le programme simule le deuxième joueur. Il n'a pas besoin de jouer brillamment, mais ses choix doivent respecter les règles du jeu. 

# Cycle de Développement

## Création de la branche
 - Prise en charge du ticket sur le Trello
 - Exécution de la commande ***git pull origin main*** pour mettre à jour notre dépôt local
 - Création de la branche depuis la branche **main** avec la commande ***git checkout -b nom_de_la_branche main***
 - Puis **CODONS !!!**
## Commit
 - Rédaction d'un message du commit explicite (en rapport avec le ticket) permettant de faire le suivi du ticket (branche)
 - Puis exécution de la commande ***git push origin nom_de_le_branche***
## Pull Request
 - Après le **pull**, nous créons une pull request afin de pouvoir faire une vérification de la validité du nouveau code de la part de git
## Review & Merge
 - Nous faisons une **review** du code de l'autre pour comprendre la logique mais également pour refactoriser le code si nécesaire
