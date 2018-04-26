/**
 * Función que va llenando la lista dinammica que contendrá los nodos de la topologia.
 * @param inicio almacena el nodo que es el inicio de la lista dinamica.
 * @param aux    auxiliar utilizada para realizar el encadenamiento.
 */
void Llenar_lista(EDIF **inicio, EDIF **aux);
/**
 * Función que despliega el contenido de la lista (topologia).
 * @param inicio almacena el nodo que es el inicio de la lista dinamica.
 */
void despliega_nodos(EDIF *inicio);
/**
 * Función que libera el espacio de memoria reservado para cada nodo de la lista dinamica.
 * @param inicio almacena el nodo que es el inicio de la lista dinamica.
 */
void limpia_nodos(EDIF *inicio);
/**
 * Función que agrega una sublista de conexiones a cada nodo.
 * @param principal Es el nodo de la lista al cual se le agregaran las conexiones.
 * @param d         almacena el nombre del nodo se va a conectar.
 */
void agregar_conexion(EDIF *principal, char d);
/**
 * Función que despliega las conexiones de cada nodo.
 * @param principal Es el nodo de la lista al cual se le agregaran las conexiones.
 */
void despliega_conexiones(EDIF *principal);
/**
 * Libera el espacio de memoria de los nodos que se almacenan en la sublista de conexiones.
 * @param principal Es el nodo de la lista al cual se le agregaran las conexiones.
 */
void limpia_conexiones(EDIF *principal);
