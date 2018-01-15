<<<<<<< HEAD
# ifndef CONTROLUNIT_H
# define CONTROLUNIT_H

# include "fullalu.h"

class ControlUnit(){
	private:
		std::vector<bit> op;
		std::vector<bit> function;
};

/* 
	3 fun��es b�sicas: busca (fetch), decodifica��o (decoding) e execu��o (execution)
	
	A UC fornece o endere�o de mem�ria de onde deve retirar um byte ou mais, conhecido como chunk,
	esse chunk pode conter um c�digo de opera��o-opcode, ou um operando tamb�m conhecido como dado.
	Lembre-se, na primeira posi��o de mem�ria deve sempre ser gravado um opcode, pois s� o opcode
	pode informar para a UC qual a��o deve ser tomada depois. Al�m de controlar a posi��o de mem�ria
	que cont�m a instru��o corrente que o computador est� executando a UC, ao decodificar o opcode,
	informa � ULA qual opera��o a executar: soma ou subtra��o nos processadores de 8 bits.
	Nos processadores de 16 bits podem ser efectuadas as instru��es de soma, subtra��o, divis�o e multiplica��o.
	
	Em adi��o a essas opera��es que chamamos de aritm�ticas, a partir da decodifica��o do opcode, a
	UC tem a capacidade de realizar opera��es que denominamos opera��es l�gicas, onde se incluem: E,
	Ou, Xor, compara��o, deslocamento de bits para a direita e para a esquerda. Essas opera��es s�o
	basicamente as mesmas para grande maioria de microprocessadores que existem no mercado. Contudo,
	cada fabricante atribui a cada uma delas um mnem�nico diferente, registra-os em um manual de
	instru��es espec�fico daquele processador, e o denomina conjunto de instru��es
	
	Uma caracter�stica muito importante de nota � que a arquitetura de um processador pode ser orientada
	de dois tipos: por registrador ou para a mem�ria.

	Se for orientada para registradores como no caso da arquitetura Intel, a ULA, ap�s executar qualquer
	opera��o l�gica ou aritm�tica, sempre vai armazenar o resultado no registrador acumulador. No caso de
	ser orientado para mem�ria, como � o caso dos microprocessadores da Motorola, nem sempre o resultado
	� armazenado no acumulador, podendo esse ser armazenado em qualquer posi��o de mem�ria. Terminada a
	primeira instru��o, a unidade de controle auto incrementa um contador, chamado de contador de programa
	e vai para a pr�xima instru��o (tipicamente localizada na pr�xima posi��o da mem�ria (endere�o de mem�ria),
	a menos que a instru��o seja uma instru��o de desvio informando o computador que a pr�xima instru��o est�
	em outra posi��o).
	
	Durante o Ciclo de Busca, � a Unidade de Controle que atua. Uma nova instru��o � buscada da Mem�ria para
	que possa ser decodificada. Nessa fase os registradores [PC] e [IR] s�o utilizados, como apresentados na
	se��o anterior. O PC � logo lido para se saber que instru��o ser� executada, essa instru��o � trazida para
	o IR e, finalmente, � decodificada pela Unidade de Controle. Assim que esse processo termina, caso a instru��o
	n�o diga respeito � um la�o, ou � uma repeti��o, o conte�do de PC � incrementado. Ou seja, PC recebe PC + 1.
	Assim, no pr�ximo Ciclo de Busca a instru��o do endere�o seguinte ser� carregada da mem�ria e executada.
	Esse comportamento garante a caracter�stica de execu��o sequencial dos programas.
	
	No passo seguinte a CPU entra em Ciclo de Execu��o. Nessa etapa atua a Unidade de Ciclo de Dados. Agora a Unidade
	de Controle j� sabe exatamente que opera��o ser� executada, com quais dados e o que fazer com o resultado. Essa
	informa��o � passada para a ULA e os registradores envolvidos. Durante o Ciclo de Execu��o h� cinco poss�veis tipos
	de opera��o que podem ser executadas:

	Processador e mem�ria
		trata simplesmente da transfer�ncia de dados entre CPU e mem�ria principal;
	Processador e Entrada e Sa�da
		diz respeito � transfer�ncia de dados entre a CPU e um dispositivo de Entrada e Sa�da, como teclado, mouse, monitor, rede, impressora etc.;
	Processamento de Dados
		s�o opera��es simplesmente de processamento dos dados, como opera��o aritm�tica ou l�gica sobre os registradores da CPU;
	Controle
		s�o instru��es que servem para controlar os dispositivos do computador, como para ligar um perif�rico, iniciar uma opera��o do disco r�gido, ou transferir um dado que acabou de chegar pela Internet para a Mem�ria Principal;
	Opera��es compostas
		s�o opera��es que combinam uma ou mais instru��es das outras em uma mesma opera��o.
		
	
*/


=======
# ifndef CONTROL_UNIT_H
# define CONTROL_UNIT_H

# include "defs.h"
# include <vector>

 // Forward declarations
class ALUControl;

class ControlUnit {
    /* Main control unit. Recieves the OP field of the instruction as an input,
    and then sets the control lines in the devices along the datapath.*/
    friend class Datapath;
private:
    ALUControl *aluControl;

    // Inputs
    std::vector<bit> op;

    // Outputs
    bit regDst, aluSrc, memToReg, regWrite, memRead, memWrite, branch, aluOp1,
    aluOp0;

public:
    ControlUnit();
    void process();
};

class ALUControl {
    /* Control for the ALU. It recieves an ALUOp from the ControlUnit and the
    funct field of the instruction. Then, it sets the control lines in the
    ALU. */
    friend ControlUnit;
    friend class Datapath;
private:
    // Inputs
    bit aluOp0, aluOp1;
    std::vector<bit> funct;

    // Outputs
    bit op1, op2, BNegate, AInvert;

public:
    ALUControl();
    void process();
};

# endif /* end of include guard: CONTROL_UNIT_H */
>>>>>>> upstream/master
