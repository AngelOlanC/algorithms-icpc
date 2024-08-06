/**
 * Descripcion: cuando se trabaja con caminos en un arbol, es util descomponer a este
 * recursivamente en sub-arboles formados al eliminar su centroide, el centroide de un arbol 
 * es un nodo u tal que si lo eliminas, este se divide en sub-arboles con un numero de nodos
 * no mayor a la mitad del original, todos los arboles tienen un centroide, y a lo mas 2.
 * Esto provoca que el arbol sea dividido en sub-arboles de distintos niveles de descomposicion,
 * por comodidad, un nodo v es un centroide ancestro de otro nodo u, si v, en algun nivel, fue el
 * centroide que separo al componente de u en sub-arboles.
 * Todo camino del arbol original se puede expresar como la concatenacion de dos caminos del tipo:
 * (u, A(u)), (u, A(A(u))), (u, A(A(A(u))))..., etc.
 * Ya que en cada nivel k el numero de nodos de algun componente es a lo mas |V| / 2^k, un nodo puede
 * estar en log |V| componentes, es decir, puede tener como maximo log |V| ancestros.
 * Tiempo: O(|V| log |V|)
 */
int calcsz(vi& szt, int u, int f){
	szt[u]=1;
	for(auto v:g[u])if(v!=f&&!tk[v])szt[u]+=calcsz(v,u);
	return szt[u];
}
void cdfs(vi& szt, vi& fat, vi& tk, int x=0, int f=-1, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto v:g[x])if(!tk[v]&&szt[v]*2>=sz){
		szt[x]=0;cdfs(szt, fat, tk, v,f,sz);return;
	}
	tk[x]=true;fat[x]=f;
	for(auto v:g[x])if(!tk[v])cdfs(szt, fat, tk, v,x);
}
void centroid(vi& szt, vi& fat, vi& tk){cdfs(szt, fat, tk);}