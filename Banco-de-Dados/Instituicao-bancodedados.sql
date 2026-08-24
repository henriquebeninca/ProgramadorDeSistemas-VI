CREATE TABLE Departamento
(
	Codigo SERIAL PRIMARY KEY,
	Nome VARCHAR (100) NOT NULL,
	Area_atuacao VARCHAR(100) NOT NULL
);

CREATE TABLE Espacos
(
	idEspacos SERIAL PRIMARY KEY,
	Nome VARCHAR(100) NOT NULL,
	Localizacao VARCHAR(100) NOT NULL,
	Capacidade_maxima INT NOT NULL
);

CREATE TABLE Evento
(
	Codigo SERIAL PRIMARY KEY,
	Nome VARCHAR(150) NOT NULL,
	Descricao TEXT,
	Data_realizacao DATE NOT NULL,
	Carga_horaria INT NOT NULL,
	idDepartamento_FK INT, FOREIGN KEY (idDepartamento_FK) REFERENCES Departamento(Codigo),
	idEspacos_FK INT, FOREIGN KEY (idEspacos_FK) REFERENCES Espacos(idEspacos)
);



CREATE TABLE Patrocinador
(
	CNPJ INT PRIMARY KEY,
	Nome VARCHAR(100) NOT NULL,
	Telefone INT NOT NULL, 
	Cidade VARCHAR(100) NOT NULL
);


CREATE TABLE Patrocinador_Evento
(
	Codigo INT, FOREIGN KEY (Codigo) REFERENCES Evento(Codigo),
	CNPJ INT, FOREIGN KEY (CNPJ) REFERENCES Patrocinador(CNPJ),
	PRIMARY KEY(Codigo, CNPJ)
);

CREATE TABLE Palestrantes 
(
	Email SERIAL PRIMARY KEY,
	Nome VARCHAR(100) NOT NULL,
	Telefone INT NOT NULL,
	Inst_de_origem VARCHAR(150) NOT NULL
);

CREATE TABLE Eventos_Palestrantes 
(
	idEventos INT, FOREIGN KEY (idEventos) REFERENCES Evento(Codigo),
	idPalestrantes INT, FOREIGN KEY (idPalestrantes) REFERENCES Palestrantes(Email)

);

CREATE TABLE Estudantes 
(
	Matricula INT PRIMARY KEY,
	Nome VARCHAR(100) NOT NULL,
	Curso VARCHAR(100) NOT NULL,
	Periodo TIME,
	Email VARCHAR(100) NOT NULL
);

CREATE TABLE Eventos_Estudantes
(	
	Matricula INT, FOREIGN KEY (Matricula) REFERENCES Estudantes(Matricula),
	Codigo INT, FOREIGN KEY (Codigo) REFERENCES Evento(Codigo)
);

CREATE TABLE Inscricao
(
	idEstudantes INT, FOREIGN KEY (idEstudantes) REFERENCES Estudantes(Matricula),
	idCertificados INT, FOREIGN KEY (idCertificados) REFERENCES Certificados(numero_unico),
	Data_da_inscricao DATE,
	Situacao_da_participacao VARCHAR(100) NOT NULL
);

CREATE TABLE Certificados 
(
	numero_unico serial primary key,
	carga_horaria TIME,
	data_emissao DATE
);

INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Nicolas', 'programação', 'manhã', 'nicolas213@gmail.com', 67676767 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('João', 'programação', 'manhã', 'joãozinho224@gmail.com', 67676768 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Marcos', 'programação', 'manhã', 'mcgamer654@gmail.com', 67676769 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Gaudâncio', 'programação', 'tarde', 'guridoalfalto76@gmail.com', 67676770 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Nicanor', 'programação', 'manhã', 'nicadosul321@gmail.com', 67676771 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Florisbela', 'programação', 'tarde', 'florisbelaa324@gmail.com', 67676772 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Jaldete', 'programação', 'manhã', 'jaldetinha3423@gmail.com', 67676773 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Vitor', 'programação', 'tarde', 'choraagoraridepois2323@gmail.com', 67676774 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Luciano Hulk', 'programação', 'tarde', 'reais1000000@gmail.com', 67676775 );
INSERT INTO Estudantes (Nome, Curso, Periodo, Email, matricula) VALUES ('Fausto', 'programação', 'manhã', 'cacetadas3234@gmail.com', 67676776 );


INSERT INTO Departamento (Codigo, Nome, Area_atuacao) VALUES (23123278, 'Departamento Acadêmico', 'Ensino médio');


INSERT INTO Inscricao (idEstudantes, Data_da_inscricao, Situacao_da_participacao, idCertificados) VALUES ('Nicolas', '12/07/2026', '') 
