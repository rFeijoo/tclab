# Instruções para instalar as dependências do biblioteca

 - Os passos à seguir foram realizados utilizando o Python 3.7.9.

## Passo 1: Criação de um Ambiente Virtual no Anaconda 

No Terminal, crie o Ambiente Virtual:

```
    $ conda create -n tclab_env python=3.7.9
```

Para ativá-lo:

```
    $ conda activate tclab_env
```

> Se o ambiente for inicializado corretamente, seu terminal deverá aparecer algo como ```(myenv)~/$```.

Para desativá-lo:

```
    $ conda deactivate
```

## Passo 2: *Download* do Repositório

No terminal, digite o comando abaixo na pasta desejada:

```
    $ git clone https://github.com/evertoncolling/tclab_jupyter.git
```

## Passo 3: Instalação

No terminal:

1. Ative o Ambiente Virtual criado e acesse o diretório ```tclab_jupyter/```.
2. Digite o comando ```pip3 install -r requirements.txt```

## Passo 4: Hello World

No terminal:

1. Com o Ambiente Virtual ativado e no diretório ```tclab_jupyter/```, abra o [Jupyter Notebook](https://jupyter.org) com o comando ```jupyter notebook```.
2. Abra o arquivo ```demo.ipynb```.
3. Execute a primeira célula, clicando em ```run```, para importar as bibliotecas necessárias.
4. Execute a segunda célula para rodar a aplicação e pressione ```Start``` para inicá-la.
5. Por fim, execute a terceira célula para ter acesso as configurações da aplicação.

> NOTA: um erro é gerado caso o valor inserido seja igual ao atual.

## Passo 5: Integração com Arduino
 
No diretório do projeto, execute:

```
git clone https://github.com/APMonitor/arduino.git
```

Por fim, entre na pasta ```arduino/0_Test_Device/Python/tclab_v2``` e carregue o arquino ```.ino``` em um Arduino Uno via [Interface Nativa](https://www.arduino.cc).

Pronto, o laboratório está pronto para uso.

   

