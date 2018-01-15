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
	3 funções básicas: busca (fetch), decodificação (decoding) e execução (execution)
	
	A UC fornece o endereço de memória de onde deve retirar um byte ou mais, conhecido como chunk,
	esse chunk pode conter um código de operação-opcode, ou um operando também conhecido como dado.
	Lembre-se, na primeira posição de memória deve sempre ser gravado um opcode, pois só o opcode
	pode informar para a UC qual ação deve ser tomada depois. Além de controlar a posição de memória
	que contém a instrução corrente que o computador está executando a UC, ao decodificar o opcode,
	informa à ULA qual operação a executar: soma ou subtração nos processadores de 8 bits.
	Nos processadores de 16 bits podem ser efectuadas as instruções de soma, subtração, divisão e multiplicação.
	
	Em adição a essas operações que chamamos de aritméticas, a partir da decodificação do opcode, a
	UC tem a capacidade de realizar operações que denominamos operações lógicas, onde se incluem: E,
	Ou, Xor, comparação, deslocamento de bits para a direita e para a esquerda. Essas operações são
	basicamente as mesmas para grande maioria de microprocessadores que existem no mercado. Contudo,
	cada fabricante atribui a cada uma delas um mnemônico diferente, registra-os em um manual de
	instruções específico daquele processador, e o denomina conjunto de instruções
	
	Uma característica muito importante de nota é que a arquitetura de um processador pode ser orientada
	de dois tipos: por registrador ou para a memória.

	Se for orientada para registradores como no caso da arquitetura Intel, a ULA, após executar qualquer
	operação lógica ou aritmética, sempre vai armazenar o resultado no registrador acumulador. No caso de
	ser orientado para memória, como é o caso dos microprocessadores da Motorola, nem sempre o resultado
	é armazenado no acumulador, podendo esse ser armazenado em qualquer posição de memória. Terminada a
	primeira instrução, a unidade de controle auto incrementa um contador, chamado de contador de programa
	e vai para a próxima instrução (tipicamente localizada na próxima posição da memória (endereço de memória),
	a menos que a instrução seja uma instrução de desvio informando o computador que a próxima instrução está
	em outra posição).
	
	Durante o Ciclo de Busca, é a Unidade de Controle que atua. Uma nova instrução é buscada da Memória para
	que possa ser decodificada. Nessa fase os registradores [PC] e [IR] são utilizados, como apresentados na
	seção anterior. O PC é logo lido para se saber que instrução será executada, essa instrução é trazida para
	o IR e, finalmente, é decodificada pela Unidade de Controle. Assim que esse processo termina, caso a instrução
	não diga respeito à um laço, ou à uma repetição, o conteúdo de PC é incrementado. Ou seja, PC recebe PC + 1.
	Assim, no próximo Ciclo de Busca a instrução do endereço seguinte será carregada da memória e executada.
	Esse comportamento garante a característica de execução sequencial dos programas.
	
	No passo seguinte a CPU entra em Ciclo de Execução. Nessa etapa atua a Unidade de Ciclo de Dados. Agora a Unidade
	de Controle já sabe exatamente que operação será executada, com quais dados e o que fazer com o resultado. Essa
	informação é passada para a ULA e os registradores envolvidos. Durante o Ciclo de Execução há cinco possíveis tipos
	de operação que podem ser executadas:

	Processador e memória
		trata simplesmente da transferência de dados entre CPU e memória principal;
	Processador e Entrada e Saída
		diz respeito à transferência de dados entre a CPU e um dispositivo de Entrada e Saída, como teclado, mouse, monitor, rede, impressora etc.;
	Processamento de Dados
		são operações simplesmente de processamento dos dados, como operação aritmética ou lógica sobre os registradores da CPU;
	Controle
		são instruções que servem para controlar os dispositivos do computador, como para ligar um periférico, iniciar uma operação do disco rígido, ou transferir um dado que acabou de chegar pela Internet para a Memória Principal;
	Operações compostas
		são operações que combinam uma ou mais instruções das outras em uma mesma operação.
		
	
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
