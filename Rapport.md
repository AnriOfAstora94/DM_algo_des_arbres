# Rapport DM_algo_des_arbres
RABE Iarimbola 
PÉGOURIÉ Benjamin

## Fonctions implémentés

### Fonctions demandés

En accord avec le travail nécessaire à effectuer dans le sujet du devoir maison, nous avons
débuter par effectuer le découpage et la création des fichiers nécessaires au bon fonctionnement
du projet, c'est-à-dire, arbre_binaires.c et .h, greffes, saages, un makefile et le main.c.

Tout d'abord, nous avons réalisé les fonctions copies et quelques fonctions de manipulation des arbres nécessaire à
l'utilisation correcte du type Arbre. Ensuite, nous nous sommes attelés à réaliser la fonction expansion (plus de détails sûr 
les fonctions intermédiaires ci-dessous), puis sérialisation et déserialisation, et enfin la fonction construire_arbre, tout cela
en respectant bien entendu les prototypes donnés dans le sujet.
Nous avons terminé par l'écriture du main (qui ne servait qu'à vérifier le bon fonctionnement de nos différentes fonctions
jusqu'à maintenant) et du rapport.

### Fonctions intermédiaires

En dehors des fonctions de manipulations d'Arbre tel que liberer, alloue_noeud, entre autres fonctions usuelles au rôle évident,

Pour nous faciliter la tâche lors de la fonction expansion, nous l'avons découpé avec les fonctions greffeG et greffeD prenant 
en paramètre le greffon et l'arbre recevant la greffe, ces fonctions servent à effectuer la copie et également à tester 
la présence d'erreur lors de l'éxecution.

Les fonctions sérialisations et déserialisations utilisent toute deux une fonction auxiliaire simplé nommé par le nom de la fonction l'utilisant suivi de _aux.
serialisation_aux est une fonction récursive s'occupant de la majeure partie du travail de serialisation, en effet, c'est elle qui
lit l'arbre reçu en paramètre et qui le traduit en fichier saage. Cette fonction est elle-même aidée par une fonction indente
qui quand à elle est appelée pour écrire l'indentation dans le fichier saage à chaque appel récursif de serialisation_aux 
lorsque cela est nécessaire.
deserialisation_aux est également récursive et reprends le principe d'une saisie utilisateur préfixe, simplement, elle lit un fichier
saage à la place des entrées d'un humain, l'indentation n'ayant aucune importance pour la conversion en mémoire, nous avons ajouté une fonction
suppr_Espaces_Debut qui comme son nom l'indique, supprime les espaces au début d'une chaîne de caractère afin de se débarasser d'une éventuelle indentation, deserialisation_aux utilise également la fonction recherche_val qui, après avoir reçu une ligne ayant une structure tel que
"Valeur : 'donnee'" (donnee représentant ici la valeure du noeud), effectue l'extraction de la donnée et la renvoie à deserialisation_aux pour
l'allocation d'un nouveau noeud.
La fonction construit_arbre utilise également une version auxiliaire, n'ayant pû déceler la signification du premier 1 dans les exemples de saisies,
nous avons fait le choix d'utiliser construit_arbre pour traiter ce premier 1 comme signalant si l'arbre et vide ou non. Si la réponse est 1,
nous utilisons construit_arbre_aux pour récuperer la valeur à donner au noeud que l'on traite, on réclame ensuite un 0 ou 1 pour savoir s'il y a un sous-arbre gauche que l'on traite le cas échéant.
Puis cette méthode est répété pour le sous-arbre droit.



Dans le cas des autres fonctions, nous n'avons pas jugés nécessaires d'utiliser plus de fonctions intermédiaires, leur rôle semblant
relativement simple.

## Difficultés rencontrés

Nous avons eu un certains nombres de difficultés lors de la réalisation du devoir, notamment une ambiguité entre parcours infixe et préfixe dans
le sujet, les exemples montrant un parcours préfixe, alors que l'énoncé textuel demande un parcours infixe.
Les fonctions expansion et deserialisations se sont également prouvés d'une difficulté certaine, cependant en prenant le temps de
bien représenter les problèmes que pose l'implémentation de ces fonctions (notamment à l'aide d'un dessin) , et en théorisant un algorithme pour écrire ensuite le code, nous avons réussi à surmonter ces difficultés.
Un fameux espace a également posé problème lors du test de serialisation, le format utilisé par notre fonction étant "Gauche :\n" dnas le cas
d'un sous-arbre gauche non nul, et celui attendu s'est en fait révélé être "Gauche : \n".

## Répartition du travail

RABE Iarimbola a débuté le DM en créant les fichiers et le makefile, il a ensuite implémenté les fonctions de manipulation d'arbre
que nous avons utilisés et la fonction expansion, une part massive du travail. Il a également finalisé la fonction serialisation et déceler
l'espace maudit, il a également effectué l'écriture du main.
Quand à moi, PÉGOURIÉ Benjamin (je me permets d'utiliser la première personne ici), j'ai effectué l'implémentation des fonctions creer_A1/2/3,
ainsi que la fonction deserialisation, également, j'ai éffectué construit_arbre, et une quantités non négligeables de documantation pour nos diverses fonctions.
Également, vous l'aurez sans doute déjà remarqué, je me suis chargé de l'écriture de ce rapport.
Bien sûr ce découpage est assez grossier, et il est arrivé plus d'une fois que l'on travaille et réflechisse ensemble
sûr des problèmes particulièrement retorses.


# Merci de nous avoir lus
