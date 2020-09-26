CREATE database fiscal;
use fiscal;

show tables;

-- 1)	Crie as seguintes tabelas para resolver as questões abaixo:
CREATE TABLE IF NOT EXISTS clientes ( 
	codigo INT(5) NOT NULL AUTO_INCREMENT,
	nome TEXT(30) NOT NULL,
	endereco TEXT(30),
	cidade TEXT(30),
	fone TEXT(12),
	PRIMARY KEY(codigo)
);

drop table clientes;

CREATE TABLE IF NOT EXISTS produtos ( 
	codigo INT(5) NOT NULL AUTO_INCREMENT,
	descricao TEXT(30) NOT NULL,
	qtde INT(5) CHECK(qtde >= 0),
	valor DECIMAL(5, 2) CHECK(valor >= 0),
	PRIMARY KEY(codigo)
);

drop table produtos;

CREATE TABLE IF NOT EXISTS notas ( 
	num_nota INT(6) NOT NULL AUTO_INCREMENT,
	cod_cli INT(5) NOT NULL,
	data_pedido DATE NOT NULL,
	PRIMARY KEY(num_nota),
	FOREIGN KEY(cod_cli) REFERENCES clientes(codigo)
);

drop table notas;

CREATE TABLE IF NOT EXISTS itens_nota ( 
	num_nota INT(6) NOT NULL,
	cod_prod INT(5) NOT NULL,
	qtde INT(5) CHECK(qtde >= 0),
	CONSTRAINT FK_NOTA FOREIGN KEY (num_nota) REFERENCES notas(num_nota),
	CONSTRAINT FK_PRODUTO FOREIGN KEY (cod_prod) REFERENCES produtos(codigo),
	CONSTRAINT PK_ITENS_NOTA PRIMARY KEY (num_nota, cod_prod)
);

drop table itens_nota;

-- 2)	a)    Insira 3 clientes e 3 produtos.
 INSERT INTO clientes (nome, endereco, cidade, fone) VALUES
('Maria Costa Martins', 'Rua Poeta Zé da Luz, 705', 'João Pessoa-PB', '58040-680'),
('Rafael Dias Gomes', 'Travessa Dois de Julho, 1891', 'Vitória da Conquista-BA', '45015-080'),
('Alex Barbosa Araujo', 'Praça Valdetario Gonçalves, 656', 'Duque de Caxias-RJ', '25070-490'),
('Amanda Carolina Araujo', 'Quadra 17, Rua A, 656', 'Samambaia', '25070-490'),
('Carlos Gomes Santos', 'Avenida proeza, 789', 'São Paulo', '54478-113'),
('Paulo Cardoso Silveira', 'Rua do sossego, quadra 17, 558', 'Samambaia', '145'),
('Bruno Teixeira Celestino', 'Avenida das pedras, 798', 'São Paulo', '56687-587');

 INSERT INTO produtos (descricao, qtde, valor) VALUES
('Fone De Ouvido Samsung Akg', 98, 60),
('Teclado sem fio Logitech', 25, 190.99),
('Lavadora Alta Pressão Smart', 667, 309.90);

-- b)	Insira 2 notas com 3 itens em cada nota, utilizando os clientes e produtos cadastrados. 
 INSERT INTO notas (cod_cli, data_pedido) VALUES
(3, '2020-05-14'),
(3, '2020-05-14'),
(4, '2020-02-02'),
(3, '2020-05-21'),
(1, '2020-06-05');

INSERT INTO itens_nota (num_nota, cod_prod, qtde) values
(1, 1, 2),
(1, 2, 1),
(1, 3, 3),
(2, 1, 4),
(2, 2, 2),
(2, 3, 1),
(3, 1, 2),
(3, 2, 1),
(3, 3, 3),
(4, 1, 1),
(4, 2, 2),
(4, 3, 3),
(5, 1, 1),
(5, 2, 2);

-- 3)	Crie uma visão com o nome Gastos_Clientes que exiba o código, nome e total 
-- gasto por cada cliente nos últimos 30 dias (CURDATE( ) – data <= 30)
CREATE VIEW Gastos_Clientes AS
SELECT N.cod_cli, C.nome
FROM notas N INNER JOIN clientes C
ON (C.codigo = N.cod_cli) 
WHERE CURDATE() - N.data_pedido <= 30;

drop view Gastos_Clientes;

select * from Gastos_Clientes;


-- 4)	Crie uma visão com código, nome e cidade dos clientes de Samambaia e São Paulo.
CREATE  VIEW Clientes_de_Sam_SP AS
SELECT codigo, nome, cidade
FROM clientes
Where cidade = 'Samambaia' OR cidade = 'São Paulo';

SELECT * from Clientes_de_Sam_SP;

-- 5)	Insira através da visão anterior os seguintes registros:
-- a)	Código = 123, nome = João e cidade = Samambaia.
	INSERT INTO Clientes_de_Sam_SP (codigo, nome, cidade) VALUES
	(123, 'João', 'Samambaia');
	
-- b)	Código = 321, nome = Ana e cidade = Gama.
	NSERT INTO Clientes_de_Sam_SP (codigo, nome, cidade) VALUES
	(321, 'Ana', 'Gama');



















-- 
CREATE TABLE IF NOT EXISTS teste (
	id integer(3) AUTO_INCREMENT,
	nome varchar (30),
	idade int(3),
	primary key(id),
	CONSTRAINT CH_IDADE CHECK(idade >= 18)
);

drop table teste;

alter table teste add primary key(id);

INSERT INTO teste(nome, idade) values
('Thiago Sousa', 23),
('Bernardo Vasconcelos', 18),
('Matheus Carlos', 21),
('Ítalo Ribeiro', 20);




