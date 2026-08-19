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

