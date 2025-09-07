Document des Exigences Logicielles (SRS) - Lot Manager

Version : 1.0
Date : 25-08-2025
Auteur : Xavier Berthiaume

# Introduction

## Objet
Ce document décrit les exigences fonctionnelles et non fonctionnelles pour le logiciel « Lot Manager ». Le but de ce logiciel est de fournir aux superviseurs d'usine un outil centralisé, fiable et intuitif pour gérer l'emplacement, l'inventaire et les paramètres spécifiques (p. ex., la température des reefers) de tous les véhicules (voitures, camions, semi-remorques) dans un parc de stockage. Ce SRS sert d'accord entre les développeurs et les parties prenantes sur les capacités du système.

## Portée du Projet
Le Gestionnaire de Parc sera une application desktop développée en C++ à l'aide du framework Qt. Il permettra aux utilisateurs de :

- Cartographier numériquement la disposition physique du parc.

- Créer et supprimer des emplacements dans le parc.

- Créer, lire, mettre à jour et supprimer les enregistrements des véhicules et de leurs positions.

- Gérer des inventaires détaillés pour chaque véhicule.

- Contrôler et surveiller les paramètres spécifiques des véhicules spécialisés (p. ex., la température des reefers).

- Garantir une haute intégrité des données pour prévenir les erreurs opérationnelles.

- Conserver un historique des déplacements individuels des véhicules.

- Authentification des utilisateurs et contrôle d'accès basé sur les rôles.

- Accès en réseau à l'application et à ses données.

Les éléments suivants sont exclus de la portée du projet :

- Le suivi GPS en temps réel des véhicules (le positionnement est mis à jour manuellement par les utilisateurs/le personnel).
 
- L'intégration avec des capteurs physiques ou des appareils IoT (version initiale).
 
- Les modules de comptabilité financière ou de facturation.
 
- Les sauvegardes de données ou la redondance des données.

## Définitions, Acronymes et Abbréviations
- *Véhicule* : Un terme général pour toute unité dans le stationnement (voitures, camions, semi-remorques).

- *Reefer* : Une semi-remorque réfrégérée, avec la capacité de contrôler sa température interne.

- *Parc* : La zone physique de la cour où les véhicules sont stockés.

- *Superviseur* : L'utilisateur primaire de ce logiciel (e.g., un contremaître de production).

- *Employé* : Personnel qui déplace les véhicules de la cour en se basant sur les instructions indiquées par le superviseur.

- *Qt* : Un framework de programmation qui est utilisé pour développer des applications avec interface graphique qui est plateforme-agnostique.

## Références
Documentation pour le framework Qt : https://www.qt.io/


# Aperçu du logiciel

## Exigences de l'utilisateur
Les superviseurs d'usine ont besoin de localiser rapidement des véhicules spécifiques, d'en vérifier le contenu et les paramètres (comme la température), et d'instruire le personnel pour les déplacer sans inspection physique de chacun, économisant ainsi du temps et réduisant les erreurs dans un environnement à volume élevé.

## Charactéristiques des Utilisateurs
Utilisateur Principal (Superviseur) : Techniquement compétent, a besoin d'un système très fiable et précis. Son objectif principal est l'efficacité et l'intégrité des données. Il n'est pas développeur logiciel mais est à l'aise avec les logiciels opérationnels complexes.

## Environement d'opération
- Système d'exploitation : Microsoft Windows 10/11

- Logiciels requis : C++17 (ou plus récent), Qt 6.x.

- Matériel : Un ordinateur de bureau équipé d'un moniteur, un clavier et une sourie.

## Contraintes de Conception et d'Implémentation

- L'application doit être développée en C++ en utilisant le framework Qt.

- Les données doivent être persistées dans une base de données locale mono-utilisateur (p. ex., SQLite pour la simplicité en V1.0).

- L'interface utilisateur doit être intuitive et nécessiter une formation minimale.


# Exigences Fonctionnelles

## 1. Gestion de la Disposition du Parc (EF1)
- EF1.1 : Le système doit permettre à l'utilisateur de définir une représentation visuelle du parc physique.

- EF1.2 : L'utilisateur doit pouvoir placer manuellement des emplacements dans le parc.

## 2. Gestion des Véhicules (EF2)
- EF2.1 : Le système doit prendre en charge un type de véhicule : Semi-remorque.

- EF2.2 : Pour tous les véhicules, le système doit stocker :
    Identifiant unique (N° de caisse pour les semi-remorques et numéros de plaque d'immatriculation pour les voitures et camions)
    Type
    Emplacement actuel dans le parc (quel emplacement)
    Date/heure de création (quand le véhicule est entré dans le parc)
    Date/heure du dernier déplacement
    Emplacement dans le parc
    Notes générales

- EF2.3 : L'utilisateur doit pouvoir Créer, Voir, Modifier et Supprimer les enregistrements de véhicules.

- EF2.4 : L'utilisateur doit pouvoir Déplacer un véhicule d'un emplacement à un autre en mettant à jour sa propriété d'emplacement.

## 3. Gestion de l'Inventaire (EF3)
- EF3.1 : Le système doit permettre à l'utilisateur de gérer une liste d'inventaire pour chaque véhicule.

- EF3.2 : Pour chaque article d'inventaire, le système doit stocker :
    Nom/description de l'article
    Quantité

- EF3.3 : L'utilisateur doit pouvoir Ajouter, Modifier et Supprimer des articles de l'inventaire d'un véhicule.

## 4. Gestion des Paramètres Spécialisés (EF4)
- EF4.1 : Le système doit permettre à l'utilisateur de marquer une Semi-remorque comme étant un Reefer.

- EF4.2 : Pour un Reefer, le système doit stocker un paramètre de Température Dernière Vérifiée et un paramètre de Température Cible.

- EF4.3 : L'utilisateur doit pouvoir voir et modifier la Température Cible pour un Reefer.

## 5. Présentation des Données et Recherche (EF5)
- EF5.1 : Le système doit fournir une vue principale montrant la disposition du parc avec les véhicules dans leurs emplacements.

- EF5.2 : L'utilisateur doit pouvoir sélectionner un emplacement pour voir les détails du véhicule qui s'y trouve.

- EF5.3 : L'utilisateur doit pouvoir rechercher un véhicule par son identifiant unique.

- EF5.4 : L'utilisateur doit pouvoir filtrer la vue du parc pour n'afficher que les Reefers.

## 6. Journal d'Historique (EF6)
- EF6.1 : Le système doit maintenir un journal persistant et immuable de toutes les opérations de déplacement de véhicules.

- EF6.2 : Ces fichiers journaux doivent être lisibles par l'application, la fonctionnalité étant accessible via un sous-menu.

- EF6.3 : Les données du journal doivent être lisibles par un humain, de préférence traduisibles.

## 7. Internationalisation (I18n) et Localisation (L10n) (EF7)
- EF7.1 : Tous les textes destinés à l'utilisateur dans l'interface graphique doivent être externalisés dans des fichiers de ressources.

- EF7.2 : L'application doit charger dynamiquement la langue appropriée (Anglais ou Français) en fonction des paramètres régionaux du système ou d'un paramètre de préférence utilisateur au démarrage.

## 8. Accessibilité Réseau (EF8)
- EF8.1 : Le logiciel peut être soit en mode réseau soit en mode local, ce qui fait référence à l'endroit d'où les données seront récupérées.

- EF8.2 : Des verrous empêcheront le même véhicule d'être modifié par deux utilisateurs simultanément.

- EF8.3 : Toutes les communications réseau doivent être chiffrées.

## 9. Fonctionnalité Multi-utilisateur (EF9)
- EF9.1 : Tous les utilisateurs auront un nom d'utilisateur, un code utilisateur et un code PIN pour accéder à leur profil.

- EF9.2 : 2 rôles utilisateur existent, un avec des privilèges d'édition, un sans (rôle observateur).

# Exigences Non Fonctionnelles

## Support Multilingue
Le logiciel, ainsi que toute documentation accompagnante, seront disponibles gratuitement en anglais et en français.

## Fiabilité
Le système doit être très stable, sans plantage non planifié pendant le fonctionnement standard.
La corruption des données doit être évitée. L'application doit gérer les erreurs de E/S de fichiers et de base de données de manière élégante.

## Intégrité des Données
Ceci est de la plus haute importance.
Le système ne doit pas permettre à deux véhicules d'être placés au même emplacement simultanément.
Toutes les actions critiques (Supprimer, Déplacer) doivent nécessiter une confirmation de l'utilisateur.
Les données doivent être enregistrées automatiquement fréquemment pour prévenir les pertes.

## Utilisabilité
L'interface graphique doit être conçue en utilisant les widgets standard de Qt pour une apparence et une convivialité familières.
Les tâches courantes (p. ex., déplacer un véhicule) doivent être réalisables en 3 clics ou moins.
La vue du parc doit être claire et épurée, en utilisant un code couleur (p. ex., pour le statut des Reefers).

## Performance
L'interface doit rester réactive lors de la gestion d'un parc de 200+ véhicules.
Le chargement de la vue principale du parc et la recherche d'un véhicule doivent être quasi instantanés.
Le logiciel devra être capable de gérer au moins 20 utilisateurs concurrents.

## Maintenabilité
Le code doit être bien commenté et adhérer aux meilleures pratiques modernes du C++.
Le schéma de la base de données doit être versionné et documenté pour permettre de futures migrations.
