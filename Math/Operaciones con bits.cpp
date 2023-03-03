//Tomando en cuenta un n�mero x e �ndices i, j (0-indexados); podemos hacer muchas cosas:

/*Tomando en cuenta el i-esimo bit, retorna:
0                       Si est� apagado
Cualquier otro valor    Si est� encendido*/
x & (1 << i);

//Apagar (si est� encendido) el i-esimo bit
x &= ~(1 << i);

//Prender (si est� apagado) el i-esimo bit
x |= (1 << i);

//Invierte el i-esimo bit
x ^ (1 << i);

//Apaga los primeros i bits
x &= (-1 << i);

//Apaga los bits en el rango [i, j]
x &= (((~0) << (j + 1)) | ((1 << i) - 1));