cmake_minimum_required(VERSION 3.16)

project(projet_cb VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- FIND QT ----
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

# ---- PROJECT SOURCES ----
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    utilisateur.h utilisateur.cpp
    article.h article.cpp
    categorie.h categorie.cpp
    interaction.h interaction.cpp
    notification.h notification.cpp
    commentaire.h commentaire.cpp
    like_dislike.h like_dislike.cpp
    database.h database.cpp
)

# ---- EXECUTABLE ----
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(projet_cb
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        auteur.h auteur.cpp
        admin.h admin.cpp
        lecteur.h lecteur.cpp
        categorie_dao.h categorie_dao.cpp
        articledao.h articledao.cpp
        admindao.h admindao.cpp
        auteurdao.h auteurdao.cpp
        interactiondao.h interactiondao.cpp
        commentairedao.h commentairedao.cpp
        likedislikedao.h likedislikedao.cpp
        utilisateurdao.h utilisateurdao.cpp
        notificationdao.h notificationdao.cpp
    )
else()
    add_executable(projet_cb ${PROJECT_SOURCES}
        main.cpp
           mainwindow.cpp
           mainwindow.h
           mainwindow.ui
    )
endif()

# ---- LINK QT LIBRARIES ----
target_link_libraries(projet_cb
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# ---- FINALIZE (Qt6 only) ----
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projet_cb)
endif()
