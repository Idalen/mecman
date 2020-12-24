Trabalho final de Sistemas Operacionais I (SSC0140) - Pac-Man
Nomes:	Daniel Martins Vieira - 11215719
	Diogo Castanho Emidio - 11297274
	Marcus Vinicius Santos Rodrigues - 11218862
	Vinicius Silva Fernandes Kuhlmann - 11215751

1. Sobre o jogo
	1.1 Como instalar
		O link para download, disponível no botão Code, precisa ser copiado e colado
		no terminal, logo em seguida ao comando gitclone. Após baixar, é necessário
		escrever make all e make run para, respectivamente, compilar e iniciar o jogo.
		Por fim, depois de fechá-lo, precisa-se escrever, novamente no terminal, make
		clean para limpar toda a memória alocada para o divertimento.
	1.2 Como jogar
		Inspirado no famoso jogo homônimo, esta versão se limita a fugir
		incessantemente de um único fantasma sem coletar quaisquer pontos. O jogador,
		tentando bater seu próprio recorde ao controlar o protagonista por meio das
		setas do teclado, tem como objetivo se manter o máximo de tempo sem ser
		atingido pelo inimigo. Quando isso acontecer, o jogo acaba.

2. Implementação
	2.1 Threads
		Criadas com o objetivo de funcionarem paralelamente e impedir acesso
		simultâneo, o código do jogo possui quatro threads, sendo que todas foram
		implementadas no arquivo GameThreads. Elas são:
			2.1.1 main: Como thread principal, além de iniciar as outras, instancia
			as variáveis usadas e executa o sistema de impressão na tela;
			2.1.2 input_thread: Lê os comandos do usuário. É válido ressaltar que a
			entrada foi feita nessa thread à parte para que o jogo não dependesse do
			jogador para a sua execução;
			2.1.3 mecman_thread: A partir dos comandos lidos, faz teste de
			consistência para validar a tecla pressionada e, se prevista, executa o
			movimento do protagonista;
			2.1.4 ghost_thread: A partir de comandos predeterminados, executa o
			movimento do antagonista.
	2.2 Semáforo
		O jogo possui apenas um semáforo, sendo ele o mutex. Funcionando de forma
		análoga ao semáforo binário, serve para evitar a condição de corrida, em que
		dois ou mais processos disputam entre si para acessar o mesmo dado. Ele foi
		utilizado a partir da biblioteca STL do C++, o sendo implementado nas threads
		mecman_thread e ghost_thread, de forma que, através dos métodos lock e unlock,
		impede que ambas acessem concorrentemente a região de memória ocupada pela
		matriz de caracteres da classe map. 

3. Execução e apresentação
	https://drive.google.com/file/d/1dGM9tb4w6EdZDvu4bLvaN5MspE7I3pZi/view?usp=sharing
