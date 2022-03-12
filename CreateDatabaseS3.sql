
DROP DATABASE IF EXISTS Juego;
CREATE DATABASE Juego;
USE Juego;
CREATE TABLE Jugador(
    id INTEGER PRIMARY KEY NOT NULL,
    username TEXT NOT NULL,
    password TEXT NOT NULL
    )ENGINE=InnoDB;

CREATE TABLE Partida(
    id INTEGER PRIMARY KEY NOT NULL,
    fecha TEXT NOT NULL,
    hora TEXT NOT NULL,
    duracion INTEGER NOT NULL,
    tablon INTEGER NOT NULL,
    ganador TEXT NOT NULL,
    num_jugadores INTEGER NOT NULL
    )ENGINE=InnoDB;

CREATE TABLE Participacion(
    idJ INTEGER NOT NULL,
    idP INTEGER NOT NULL,
    FOREIGN KEY (idJ) REFERENCES Jugador(id),
    FOREIGN KEY (idP) REFERENCES Partida(id)
    )ENGINE=InnoDB;


INSERT INTO Jugador VALUES (1,'Juan','Juan1');
INSERT INTO Jugador VALUES (2,'Pedro','Pedro2');


INSERT INTO Partida VALUES (1,'11.03.22','12:56',12,1,'Juan',2);


INSERT INTO Participacion VALUES (1,1);
INSERT INTO Participacion VALUES (2,1);



