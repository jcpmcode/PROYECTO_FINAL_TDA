/**
 * Se llena la matriz de adyacencia a partir del contenido del archivo.
 * @param mat    Almacena la matriz de adyacencia.
 */
void Llenar_matriz_adyacencia(int **mat);
/**
 * Se llena la lista dinamica a partir de la matriz de adyacencia.
 * @param inicio Es el pointer que almacena el nodo de inicio.
 * @param aux    Auxiliar utilizado para realizar el encadenamiento de la lista dinamica que representa la topologia.
 * @param mat    Almacena la matriz de adyacencia.
 */
void Llenar_lista(EDIF **inicio, EDIF **aux, int **mat);
/**
 * Función que despliega la lista ya generada.
 * @param inicio Es el pointer que almacena el nodo de inicio.
 */
void despliega_lista(EDIF *inicio);
/**
 * Función que libera el espacio de memoria asignado a cada nodo de la lista.
 * @param inicio Es el pointer que almacena el nodo de inicio.
 */
void limpia_lista(EDIF *inicio);
/**
 * Función que agrega las conexiones que tiene cada nodo.
 * @param principal principal es el nodo en el que se encuentra al momento de llamar a la funcion.
 * @param mat    Almacena la matriz de adyacencia.
 * @param i         Contador utilizado para desplazarse por los renglones de la matriz.
 * @param j         Contador utilizado para desplazarse por las columnas de la matriz.
 */
void agrega_conexiones(EDIF *principal, int **mat, int i, int j);
/**
 * Función que libera el espacio de memoria de las conexiones de los nodos.
 * @param principal principal es el nodo en el que se encuentra al momento de llamar a la funcion.
 */
void limpia_conexiones(CON *principal);
/**
 * Función que despliega las conexiones que tiene cada nodo.
 * @param principal principal es el nodo en el que se encuentra al momento de llamar a la funcion.
 */
void despliega_conexiones(EDIF *principal);
