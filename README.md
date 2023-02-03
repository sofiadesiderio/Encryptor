### CRIPT.COM

Esté é uma pequeno <em>script</em>, feito em C, que visa criptografar e descriptografar arquivos .txt com chave simétrica personalizada.

Vale mencionar que é possível surgir alguns erros de desconversão, visto que a maioria dos editores de texto exitam em abrir arquivos com caracteres atípicos. Mas essa questão é facilmente resolvida quando você abre os arquivos e, por contra própria, corrige os <em>bugs</em>.

#### para executar >>>

Bom, você vai precisar do GCC instalado e atualizado, e só isso mesmo :) 

1. compilando: 

   <code>gcc -o nome_que_vc_quiser main.c</code>

2. executando:

   <code>./nome_que_vc_escolheu <b style="color: #ED6A5A">endereço_do_arquivo.txt</b></code>

O programa tem uma CLI (<em>Command Line Interface</em>) simples, que permite você escolher se deseja criptografar ou descriptografar o <b style="color: #ED6A5A">arquivo passado como parâmetro</b> na execução.

#### e as pastas?

É importante que você não altere o nome das pastas, ou o caminho delas. O código inteiro foi pensado com elas da forma que está aí. Nesse sentido, se for mudar algo, encarregue-se de fazer as devidas alterações na função <em>adress()</em>.

#### lógica da encriptação com um exemplo o_o

-> texto de exemplo: "caneta"

O algoritmo vai ler caractere por caractere do texto, e converter ele para o valor correspondente na tabela ASCII.

-> texto de exemplo: "c" - "a" - "n" - "e" - "t" - "a"

Vamos supor que nossa chave é "abcd".

Cada valor numérico resultante da conversão irá ser multiplicado por uma posição da chave (que também terá sido convertido pra ASCII).

Ou seja: "c" multiplica por "a"; "a" multiplica por "b"; "n" multiplica por "c"; "e" multiplica por "d"; "t" multiplica por "a"; e vai assim até acabar o texto...



