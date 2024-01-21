# Alura_cursos
Cursos feitos na plataforma Alura

## Curso 01: C++: Conhecendo a linguagem e a STL

<h3>Primeiro curso da formação C++:</h3>
<ul>
  <li>Começando com a linguagem</li>
  <ul>
    <li>Como compilar e rodar programas em C++</li>
    <li>Como imprimir valores usando o cout </li>
    <li>Como pular linhas na saída usando o endl </li>
  </ul>
  <li>Criar um jogo da adivinhação</li>
  <ul>
    <li>Como ler valores usando o cin</li>
    <li>Como declarar e usar variáveis do tipo bool </li>
    <li>Como utilizar o identificador const na declaração de variáveis </li>
    <li>Como utilizar variáveis do tipo double</li>
    <li>Como formatar a saída para imprimir números com precisão definida</li>
    <li>Como usar a função srand() para determinar a semente dos valores aleatórios</li>
    <li>Como usar a função rand() para gerar valores aleatórios</li>
    <li>Como usar a função módulo, ou resto de divisão, denotada por % para conseguir valores aleatórios menores </li>
  </ul>
  <li>Criar um jogo da forca</li>
  <ul>
    <li>Como usar variáveis do tipo String</li>
    <li>Como usar laços de repetição do C++11</li>
    <li>Como escrever um Makefile para compilar arquivos de C++ mais facilmente </li>
  </ul>
  <ul>
    <li>Como inserimos valores em uma variável do tipo vector</li>
    <li>Como imprimir os valores de um vector usando o for em intervalos</li>
    <li>Como descobrir o tamanho de um vector, usando o método size()</li>
  </ul>
</ul>







<hr>
<h1>APÊNDICE </h1>
<h3>Curso 01</h3>
<ol>
  <li> Use o comando "g++ <em>nome_do_arquivo.cpp</em> -o <em>nome_do_arquivo_"</em> para compilar o código</li>
    <li> Para compilar um código no padrão do C++ 11 usa-se o comando "g++ <em>nome_do_arquivo.cpp</em> -o <em>nome_do_arquivo_"</em> -std=c++11"</li>
  <li> Uma alternativa para o comando acima é criar uma arquivo Makefile na pasta onde está o <em>nome_do_arquivo.cpp</em> e dentro do Makefile escrever CXXFLAGS= -std=c++11.</li>
  <li> Para compilar o código o comando se reduz para:
    <ul>
      <li> Linux: "make <em>nome_do_arquivo_</em>"</li>
      <li> Windows: "mingw32-make <em>nome_do_arquivo</em>" (certifique-se de instalar o pacote mingw antes).</li>
    </ul>
  </li>
  <li> Para executar um arquivo compilado, usa-se o comando ".//nome_do_arquivo"</li>
</ol>