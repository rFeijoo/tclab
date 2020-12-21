# Laboratório TCLAB

 - Os passos à seguir foram realizados utilizando Python 3.7.9.

## Passo 1: Criação de um Ambiente Virtual no Anaconda 

No Terminal, crie o Ambiente Virtual:

```
    $ conda create -n tclab_env python=3.7.9
```

Para ativá-lo:

```
    $ conda activate tclab_env
```

> Se o ambiente for inicializado corretamente, seu terminal deverá aparecer algo como ```(myenv)``` atrás do caminho do diretorio do seu terminal.

Para desativá-lo:

```
    $ conda deactivate
```
## Passo 2: Instalação das Bibliotecas

No terminal:

1. Digite o comando ```pip install tclab```;
2. Caso queira testar os exemplos do *GEKKO*, digite o comando ```pip install gekko```;


## Passo 3: *Download* do Repositório

No terminal, digite o comando abaixo na pasta de trabalho desejada:

```
    $ git clone https://github.com/rFeijoo/tclab.git
```

## Passo 4: Integração com Arduino
 
No diretório do projeto, entre na pasta ```tclab/arduino/tclab/```, abra o arquivo ```tclab.ino``` e o carregue em um *Arduino Uno* via [Arduino IDE](https://www.arduino.cc).

Pronto, o laboratório está apto para uso.

## Passo 5: Utilização

1. Para começar, ative o Ambiente Virtual e deixe o Arduino programado com o código ```tclab.ino```. Lembre-se de não abrir o *Serial Monitor*, já que o laboratório se comunica via interface Serial. 

2. Abra o a pasta ```tclab/python/0_Test_Device/```, e execute algum dos códigos para validar o funcionamento da interface.

3. Após validar o *hardware*, explore os outros códigos ```.py```.


