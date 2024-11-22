## Configuration du projet avec SFML

### Étape 1 : Téléchargez SFML
- Téléchargez la version adaptée à votre système depuis [SFML Downloads](https://www.sfml-dev.org/download.php).
- Assurez-vous de télécharger la version compatible avec votre compilateur (par exemple, Visual Studio 2022).

### Étape 2 : Configurez le projet
- Ajoutez le chemin vers `SFML/include` dans les Include Directories de votre IDE.
- Ajoutez le chemin vers `SFML/lib` dans les Library Directories de votre IDE.
- Liez les bibliothèques nécessaires (`sfml-graphics`, `sfml-window`, etc.).
- Copiez les fichiers `.dll` dans le dossier contenant l'exécutable généré.
