# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data
Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin vers data>`.

# Veille technologique
## Les fonctionnalités implémentées
Les fonctionnalités que j'ai choisi d'implémenter sont la numérotation automatique des ID utilisateurs (Interface et Expérience Utilisateur [Au choix]), le tri des résultats par titre, auteur pour l’affichage (Gestion des Données [Au choix]), la création si non-existant et la conservation au fur et à mesure des sessions (Journal d'activités [Obligatoire]) et la correction de l'échec de sauvegarde sans message explicite lorsque le chemin n'est pas mentionné (Correction du bug [Obligatoire]).

### Question 1 : C++
Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours. Montrez ici l’exemple sorti du code du projet.
> Une des fonctionnalité / notion dans le code que nous n'avons pas ou peu vu en cours consistait à l'intégration de la journalisation d'activités pour l'ajout, le retrait, l'emprunt et le retour d'un livre par un système de logs utilisant <fstream> et <ctime>. En combinant les fonctions de temps (time, localtime, strtfime), on génère un format date-heure (YYYY/MM/DD HH:MM:SS) pour chaque action pour ensuite l'écrire par le mode "iso::app" dans un fichier sans en y écraser le contenu tout en vérifiant que le fichier s'ouvre proprement, un fichier qu'on créer si non-existant.

```
// CODE
void FileManager::writeLog(string& action, string& details){
    ofstream saveFile(logsFileName, ios::app);

    if (saveFile.is_open()){
        time_t now=time(nullptr);
        char timeStamp[25];
        strftime(timeStamp, sizeof(timeStamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

        saveFile << timeStamp << " - [" << action << "] " << details << endl;
        saveFile.close();
    } else {
        cout << "Erreur : Impossible d'afficher le contenu " << logsFileName << "\n.";
    }
}

// RÉSULTATS
2026-10-15 03:51:07 - [EMPRUNT LIVRE] Les Contemplations|Victor Hugo|9782070380932|Anne-Sophie Kauffmann|
```

### Question 2 : Options de développement possible
Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Quelle solution technologique utiliseriez vous ? Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres.
> Pour la gestion de la bibliothèque en faisant appel éventuellement à une nouvelle technologie autre que le C++, une solution adaptée pourrait être de migrer notre sauvegarde présentement locale vers une architecture client-serveur permettant la conservation des milliers voire des millions de livres.
>
> En y ajoutant une base de données NoSQL à un serveur Python et un API pour gérer les requêtes ça nous permettrait de garder notre application en C++ pour servir de client léger. 
>
> Étant donné que le C++ reste jusqu'à ce jour un des langages les plus utilisés en programmation, il y a possibilité d'en conserver son utilisation dans le code actuel surtout pour des questions de gestion de mémoire et de gestion de performance au sein de notre programme (optimisation).

###### Par Anne-Sophie Kauffmann (DA201747491)