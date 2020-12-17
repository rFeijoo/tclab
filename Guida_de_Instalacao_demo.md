# Instruções para instalar as dependências do biblioteca

## Passo 1 : Criar um novo ambiente no Anaconda 

 - Nos testes foi usado a versão do python 3.7.9 mais deve funcionar para as versões mais recentes.

### Terminal 

```
    $ conda create -n myenv python=3.7.9
```
### Anaconda Navigator

 - Abri o Anaconda Navigator
 - No canto esquerdo, aperte em Environment
 - Depois no canto inferior, aperte em Create

## Passo 2 : Ativar o ambiente anaconda criado

### Terminal

```
    $ conda activate myenv
```

 - Mostrando que o ambiente myenv está ativado

```
    (myenv)~/$
```

## Passo 3 : Baixar o repositório

### Git clone

 - Execute esse comando na pasta aonde irá colocar o repositório no seu armazenamento local

```
    $ git clone https://github.com/evertoncolling/tclab_jupyter.git
```

### Pasta zip

 - Vai até o link : https://github.com/evertoncolling/tclab_jupyter
 - Aperte no botão verde Code, e irá aparecer um menu de opções
 - Vai na opção Download ZIP
 - Depois decompacte a pasta no local aonde deseja colocar

## Passo 4 : Instalar dependências 

### Terminal

 - Com o ambiente myenv ativado
 - Acesse a pasta do ```tclab_jupyter-master```
 
```
    (myenv)~/tclab_jupyter-master$
```
 
 - Depois coloque o comando para instalar as dependências sozinhas

```
    (myenv)~/tclab_jupyter-master$ pip3 install -r requirements.txt
```
## Passo 5 : Executar codigo exemplo

 - Depois de ter finalizado os passos anteriores, agora vamos testar o exemplo ```demo.ipynb```

### Jupyter Notebook
 
 - Com o ambiente myenv ativado
 - Coloque no terminal 

```
    (myenv)~/tclab_jupyter-master$ jupyter notebook
```

 - Abre o arquivo ```demo.ipynb```

 - Rode a primeira célula para importar as bibliotecas

 - Rode a segunda célula para ter acesso ao app, aperte o Start para dar inicio a simulação

 - Rode a terceira célula para ter acesso as configurações, lembre que irá aparecer um erro se aplicar um valor igual ao anterior

 
## Passo 6 : Executar codigos no arduino

 - Colocar os exemplos em prática com arduino  
 
###  Tclab exemplos no arduino

 - Para mais exemplos, será necessário baixar outro repositório

```
    (myenv)~/tclab_jupyter-master$ git clone https://github.com/APMonitor/arduino.git
```

 - Entre em arduino-master

```
    (myenv)~/tclab_jupyter-master$ cd arduino-master
```
```
    (myenv)~/tclab_jupyter-master/arduino-master$
```

### Baixar firmware para o arduino

 - Entrar em 0_Test_Device, depois em Python e por fim em tclab_v2 

```
    (myenv)~/tclab_jupyter-master/arduino-master$ cd 0_Test_Device/Python/tclab_v2
```

 - Abrir o arquivo tclab_v2.ino no Arduino IDE e carregar o código no arduino uno

### Testar exemplos

 - Até aqui, tudo está pronto para funcionar
 - Os exemplos estarão na pasta arduino-master
 - Os exemplos terão como referência a linguagem de programação na qual está querendo se usar

   

