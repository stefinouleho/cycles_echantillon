# MCES graphe de cycles pour l'article ( 10000 molécules de nombre de cycles supérieur ou égal à 3)



*Make run  pour lancer le programme. 


Calcule le degré de similarité avec l'algorithme MCES sur les graphes de cycles 

Contraintes :

- La base de données de molecules utilisée est CHEBI, il faut télécharger le fichier CHebi_Lite.pdf(https://www.dropbox.com/s/4qqrg5jxi8o727w/ChEBI_lite.sdf?dl=0) et le mettre dans le dossier.


- Contient un programme pour travailler avec SCIP, solveur de programmes mathématiques, en particulier de programmes linéaires. Pour l'utiliser sur Linux, il faut:
== Télécharger SCIP Optimization suite (http://scip.zib.de/#download) dans le dossier de votre choix
== Décompresser l'archive
== Aller dans le dossier scipoptsuite-X.X.X où X.X.X est la version de SCIP installée
== Exécuter la commande make scipoptlib après avoir installé les dépendances (libpopt-dev, libncurses5-dev, libreadline-dev, libreadline6-dev, libtinfo-dev, zlib1g-dev, libgmp3-dev, libgmp-dev sur debian ou ubuntu)
== Revenir dans le dossier MCES
== Rajouter dans le dossier helpers deux liens symboliques:
=== ln -s CheminVersScipoptsuite-X.X.X/scip-X.X.X/src/ scip
=== ln -s CheminVersScipoptsuite-X.X.X/lib/libscipopt.a sciplib.a

//fin des contraintes

On va calculer la similarité sur les graphes de cycles . 

Explications des résultats: 

Dans le fichier similarite.result

Sur la ligne i nous avons la mesure de similarité de la molecule d'indice i-1 avec les molecules dindice 0 à i-2

                      similarité in [0 .. 1] : valeur de similarité entre mol1 et mol2. Plus similarité tend vers 1 plus les molécules sont similaires.
                      
                      


Dans le fichier temps.result  :  temps de calcul 

Le caccul se fait en triangle, on sauvegarde l'etat donc aucun soucis si le programme s'arrete en chemin.              

A JOUR
