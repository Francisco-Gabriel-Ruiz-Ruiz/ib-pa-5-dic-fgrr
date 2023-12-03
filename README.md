# IB-Problemas-5-Diciembre
Adjunto en este repositorio de GitHub los problemas de la Hoja 4 (Clases) de Informática Básica.

Hoja 4: https://docs.google.com/document/d/1fhEb_ZNedTt9hqpUGUrurLdboTgmFIaW3wRv39iL4qU/edit

Todos los programas requieren el uso del Makefile adjuntado si desea ejecutarlos.
Programas desarrollados por Francisco Gabriel Ruiz Ruiz
1º Ingeniería Informática, Universidad de La Laguna

## C3-Car_class
Este programa lee los datos de los coches que desee y los imprime en un cierto orden. Introduzca separado por un espacio del comando la cantidad de coches que desea documentar. Se le pedirá el nombre del coche, su tipo, modelo y precio más adelante en el programa. Este organizará todos los coches que ha detallado en su tipo, y adjuntará el precio más alto de los coches que se encuentren en un mismo grupo.

`./car_class-c3 <número_de_coches_que_desea_detallar>`

No tuve claro si el programa debía incluir de manera predeterminada los 5 tipos que aparecen en el resultado del enunciado, o si el programa debía adaptarse e incluir los tipos que el usuario solicitara. Dado que si el programa se adapata dinámicamente a lo que el usuario introduce lleva a un resultado similar al primero, he implementado esta característica.

## C6-Graph_class
Este programa lee los datos de un grafo, comprueba si es correcto y lo imprime de nuevo. Se asume que los vértices del grafo vendrían numerados de 0 al número total de vértices menos uno.

Desarrollé dos versiones del mismo programa; para introducir los datos a través del teclado, diríjase a `Entrada_por_teclado`. Para que los datos se le pasen al programa mediante un fichero, diríjase a `Entrada_por_fichero`.

En esta última carpeta, hallará una serie de ficheros de texto que faciliten el uso del programa. Los ficheros que acaban en `...-erronea.txt` intencionalmente proporcionan un grafo incorrecto. Si desea desarrollar sus propios ficheros para pasar por el programa, recuerde que el número `-1` le indica al programa que su lectura de pares de vértices concluye. Uso del programa:

`./graph_class-c6-fichero <fichero_de_entrada> <fichero_de_salida>`
(Incluya las extensiones si los ficheros que desea comprobar la tienen)

Para ejecutar el programa por teclado en `Entrada_por_teclado`:

`./graph_class-c6-teclado`
(A partir de su ejecución, el programa le guiará para introducir todos los datos del grafo)


