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

> Se o ambiente for inicializado corretamente, seu terminal deverá aparecer algo como ```(myenv)``` atrás do caminho do diretorio do seu terminal.

Para desativá-lo:

```
    $ conda deactivate
```
## Passo 2: Instalação

No terminal:

1. Digite o comando ```pip install tclab```


## Passo 3: *Download* do Repositório

No terminal, digite o comando abaixo na pasta desejada:

```
    $ git clone https://github.com/evertoncolling/tclab_jupyter.git
```

## Passo 4: Integração com Arduino
 
No diretório do projeto, entre na pasta firmware e abra o arquivo tclab.ino:

Por fim, entre na pasta ```firmware/``` e carregue o arquino ```tclab.ino``` em um Arduino Uno via [Arduino IDE](https://www.arduino.cc).

Pronto, o laboratório está apto para uso.

## Passo 5: Utilização

No terminal:

1. Com o Ambiente Virtual ativado e no diretório ```arduino/```, encontra diversos exemplos de utilização.

2. Para começar, abra o a pasta ```0_Test_Device/```, lá se encontra exemplos basicos para validar a comunicação do Arduino com o Python. 


