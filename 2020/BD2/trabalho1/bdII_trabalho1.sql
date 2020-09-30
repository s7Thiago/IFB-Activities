CREATE database fiscal;
use fiscal;

show tables;

show databases;

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

INSERT INTO notas (cod_cli, data_pedido) VALUES
(123, '2020-08-29');

INSERT INTO itens_nota (num_nota, cod_prod, qtde) VALUES
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

INSERT INTO itens_nota (num_nota, cod_prod, qtde) VALUES
(6, 3, 101),
(6, 2, 99);

-- 3)	Crie uma visão com o nome Gastos_Clientes que exiba o código, nome e total 
-- gasto por cada cliente nos últimos 30 dias (CURDATE( ) – data <= 30)
CREATE VIEW Gastos_Clientes AS
SELECT N.cod_cli, C.nome, sum(P.valor * I.qtde) AS total_gasto
FROM notas N INNER JOIN clientes C ON(C.codigo = N.cod_cli)
INNER JOIN itens_nota I ON (I.num_nota = N.num_nota)
INNER JOIN produtos P ON (P.codigo = I.cod_prod)
WHERE DATEDIFF(CURDATE(), N.data_pedido) <= 30
GROUP BY C.codigo;

drop view Gastos_Clientes;

select * from Gastos_Clientes;

SELECT CURDATE();


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

-- 6)	Crie uma visão com o código, descrição, quantidade vendida (soma das qtde) e total 
-- arrecadado com as vendas de cada produto nos últimos 30 dias (CURDATE( ) – data <=30).
CREATE VIEW Lucro_por_produto AS
SELECT I.cod_prod, P.descricao, sum(I.qtde) AS vendidos, sum(I.qtde * P.valor) AS valor_arrecadado
FROM itens_nota I INNER JOIN notas N ON (N.num_nota = I.num_nota)
INNER JOIN produtos P ON (P.codigo = I.cod_prod)
WHERE DATEDIFF(CURDATE(), N.data_pedido) <= 30
GROUP BY P.codigo;

DROP view Lucro_por_produto;

SELECT * FROM Lucro_por_produto;

-- 7)	Usando a visão anterior mostre o código e descrição dos produtos que já foram 
-- vendidos em mais do que 100 unidades.
SELECT cod_prod as codigo, descricao 
FROM Lucro_por_produto
WHERE vendidos > 100;

-- 8)	Crie uma visão com o código e o nome dos clientes e a relação dos produtos (código, 
-- descrição, quantidade e valor pago) comprados por eles nos últimos 30 dias.
CREATE VIEW  Gastos_por_cliente AS
SELECT C.codigo, C.nome, I.cod_prod, P.descricao, I.qtde, (I.qtde * P.valor) as Total
FROM clientes C 
INNER JOIN notas N ON(C.codigo = N.cod_cli)
INNER JOIN itens_nota I ON(I.num_nota = N.num_nota)
INNER JOIN produtos P ON(P.codigo = I.cod_prod)
WHERE (curdate() - N.data_pedido) <= 30;

DROP VIEW Gastos_por_cliente;

SELECT * FROM Gastos_por_cliente;

-- 9)	Consulte a visão anterior e exiba o nome dos clientes que compraram o produto de 
-- descrição ‘Mesa Redonda de Mogno’ nos últimos 30 dias.
SELECT G.nome
From Gastos_por_cliente G
INNER JOIN notas N ON(N.cod_cli = G.codigo)
INNER JOIN produtos P ON(P.codigo = G.cod_prod)
WHERE G.descricao = 'Mesa Redonda de Mogno'
AND (curdate() - N.data_pedido) <= 30;

-- 10)	Crie uma visão com os dados dos produtos (código, descrição e quantidade em estoque) 
-- que não foram vendidos desde 01/01/2019.
CREATE VIEW Nao_vendidos AS
SELECT I.cod_prod, P.descricao, P.qtde
FROM produtos P
INNER JOIN itens_nota I ON(I.cod_prod = P.codigo)
INNER JOIN notas N ON(N.num_nota = I.num_nota)
WHERE P.codigo NOT IN (SELECT cod_prod FROM itens_nota WHERE N.data_pedido > '2020-01-01');

DROP VIEW Nao_vendidos;

SELECT * FROM Nao_vendidos;

-- 11)	Usando a visão do exercicio anterior mostre a descrição dos produtos que ainda não 
-- foram vendidos em 2018 e que tem mais do que 100 unidades em estoque.
SELECT NV.descricao
FROM Nao_vendidos NV
INNER JOIN  produtos P ON(P.codigo = NV.cod_prod)
INNER JOIN itens_nota I ON(NV.cod_prod = I.cod_prod)
INNER JOIN notas N ON(N.num_nota = I.num_nota)
WHERE N.data_pedido NOT IN (SELECT data_pedido FROM notas WHERE data_pedido > '2020-12-31');

-- 12)	Atualize os preços dos produtos de acordo com a seguinte regra:
-- -	produtos com custo < 100 reais terão 10% de aumento.
-- -	demais produtos terão 20% de aumento.
UPDATE produtos
SET valor = valor + (valor * 0.1)
WHERE valor < 100;

UPDATE produtos
SET valor = valor + (valor * 0.2)
WHERE valor >= 100;

-- 13)	Remova os dados de um dos produtos bem como as respectivas vendas deste a partir de 
-- sua descrição.
DELETE from P.* from produtos P
INNER JOIN itens_nota I ON(I.cod_prod = P.codigo)
INNER JOIN notas N ON(N.num_nota = I.num_nota)
WHERE p.descricao = 'descrição do produto que será apagado';

-- 14)	Altere a estrutura da tabela de itens_nota incluindo o campo preço_unit número (5,2) >=0.
-- Este campo irá informar o preço unitário do produto no dia da compra.
ALTER TABLE itens_nota
ADD COLUMN preco_unit decimal(5, 2);

-- 15)	Crie um procedimento que atribua ao campo preço_unit o preço do produto para cada registo 
-- cadastrado na tabela de itens_nota.
CREATE PROCEDURE precoProduto()
	UPDATE itens_nota 
		INNER JOIN produtos as P ON(P.codigo = itens_nota.cod_prod)
		SET preco_unit = P.valor
	WHERE itens_nota.cod_prod = P.codigo;

DROP PROCEDURE precoProduto;

CALL precoProduto;

-- 16)	Crie uma função que receba o número da nota e calcule o total gasto naquela nota (soma dos 
-- preços unitários * qtde vendida de cada item da nota).
CREATE FUNCTION totalNota(num_nota INT(6))
	RETURNS void
	
		 SELECT sum(p.valor * i.qtde) 
		FROM itens_nota i 
		INNER JOIN notas n ON (i.num_nota = n.num_nota)
		inner JOIN produtos p ON (p.codigo = i.cod_prod)
		WHERE i.num_nota = 1;
	
	DROP FUNCTION totalNota;

SELECT totalNota(1);


-- 17)	Crie um gatilho que seja executado toda vez que um novo registro for inserido na tabela de 
-- Itens_Nota. O gatilho deve reduzir do estoque a quantidade vendida do produto em questão. Teste 
-- este gatilho para verificar se ele funciona adequadamente.


-- 18)	 Crie um outro gatilho que seja executado toda vez que houver uma alteração do valor da qtde 
-- da tabela de Itens_Nota . Neste caso a quantidade em estoque deve ser atualizada pela diferença 
-- entre o valor antigo e o novo da qtde na tabela de vendas. Teste este gatilho para verificar se 
-- ele funciona adequadamente.


















