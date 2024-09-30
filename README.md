## Visão Geral
Este código em C para um microcontrolador AVR implementa um sistema de controle de motor que se baseia em um sensor de distância. O motor se move para frente até detectar um objeto a uma distância menor ou igual a um limite predefinido, momento em que ele reverte por um curto período e, em seguida, para.

## Requisitos de Hardware
- Microcontrolador AVR (ex: ATmega16, ATmega328)
- Sensor de distância (ex: HC-SR04)
- Motor DC
- Driver de motor (ex: L298N)
- Fonte de alimentação adequada
- Fios de conexão

## Funcionalidades
- **Controle de Movimento**: O código controla um motor DC, permitindo movimento para frente e para trás.
- **Leitura de Distância**: Utiliza um sensor de distância para medir a proximidade de objetos.
- **Reversão Automática**: O motor reverte automaticamente ao detectar um objeto a uma distância definida.
- **Controle PWM**: O sistema utiliza PWM para controlar a velocidade do motor de forma suave.

## Estrutura do Código

### Definições e Inicializações
- `F_CPU`: Define a frequência do microcontrolador como 16 MHz.
- `limite`: Uma variável global que define o limite de distância para o sensor.

### Inicialização das Entradas e Saídas (`init_IO`)
- Configura os pinos das portas B e D como entrada ou saída, conforme necessário para controlar o motor e ler do sensor.

### Movimento do Motor
- **`frente`**: Ativa o motor para mover para frente.
- **`tras`**: Ativa o motor para reverter.
- **`parar`**: Para o motor.

### Leitura do Sensor de Distância (`sensor_distancia`)
- Gera um pulso para o sensor de distância e calcula o tempo até o eco retornar, determinando a distância do objeto.

### Inicialização do PWM (`init_pwm`)
- Configura o Timer 2 para controlar o PWM e definir a velocidade do motor.

### Loop Principal (`main`)
- O loop principal executa as seguintes tarefas:
  1. Chama a função `frente()` para mover o motor.
  2. Verifica a distância com o sensor.
  3. Se a distância for menor ou igual ao limite, chama a função `tras()` para reverter o motor, seguida por um atraso e a função `parar()`.

## Como Funciona
1. **Inicialização**: O microcontrolador é inicializado configurando as entradas, saídas e PWM.
2. **Movimento Contínuo**: O motor se move para frente continuamente até que um objeto seja detectado pelo sensor de distância.
3. **Reversão e Parada**: Ao detectar um objeto, o motor reverte por um tempo definido antes de parar.

## Compilação e Uso
- Para compilar e carregar o código, utilize um ambiente de desenvolvimento compatível com AVR, como Atmel Studio.
- Conecte o microcontrolador ao sensor de distância e ao driver do motor.
- Após programar o microcontrolador, o motor começará a se mover e a resposta ao sensor de distância será automática.

## Notas
- Verifique se as conexões estão corretas e se a fonte de alimentação é adequada para o motor.
- O valor do limite de distância pode ser ajustado conforme necessário para diferentes aplicações.
- Este código assume que o sensor de distância está funcionando corretamente e que não há obstruções que possam interferir nas leituras.
