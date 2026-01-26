# Time Motor
Projeto Automasensor: Time Motor-02

# Escopo
Projeto com a finalidade de testar um equipamento, por hora não possui finalzidade de virar um produto.  <br>
Utiliza a placa CPA-01 V1. ABR/22. <br>
<br>
A placa lê uma entrada digital para ligar um motor, em pote H. <br>
Com o motor ligado aciona para um sentido por x segundos e para o outro 15 segundos. <br>
A entrada analógica determina o tempo que fica ligado no primeiro sentido (entre 1 e 60 segundos). <br>

# Alterações no Hardware
A placa deve ser montada conforme BOM original. Mas deve-se removoer o U4. <br>
Fazer um jumper entre o pino 2 do pic para o pino 2 do U4. <br>
O R6 deve ser 0R. <br>
A entrada analógica será na entrada IN2 do CC2. <br>
O potenciômetro deverá ser montado da seguinte forma: GND - SINAL(IN2) - +5V. <br>