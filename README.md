# Time Motor
Projeto Automasensor: Time Motor

# Escopo
Projeto com a finalidade de testar um equipamento, por hora não possui finalzidade de virar um produto.  <br>
Utiliza a placa ECU-GPS V1, não necessitando a placa superior, apenas a inferior. <br>
<br>
A placa lê uma entrada digital para ligar um motor, em pote H. <br>
Com o motor ligado aciona para um sentido por x segundos e para o outro 60 segundos. <br>
A entrada analógica determina o tempo que fica ligado no primeiro sentido (entre 1 e 30 segundos). <br>

# Alterações no Hardware
Foi criada uma bom específica para essa aplicação, que usa a pci ecu gps v1. <br>
O mais importante são os valores dos resistores da entrada analógica, que são: R23 = 18k/1%, R24 = 0R, R25 = 6k8/1% e R26 = aberto. <br>
A entrada analógica fica desenvolvida para ter entre 0 e 12V. <br>
<br>
No cliente foi colocando o potenciometro variando entre 0-3v3 na entrada analógica. R23 e R24 = 0R. R25 e R26 = aberto. <br>