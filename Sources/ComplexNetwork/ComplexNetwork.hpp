
#ifndef COMPLEX_NETWORK__CPP
#define COMPLEX_NETWORK__CPP


#include "Edge.hpp"
#include <list>
#include <algorithm>
#include <map>

/** \brief Rede Complexa
 *  \details Rede Complexa utilizando listas de adjacências
 * **/



template <class NODE_TYPE, class EDGE_TYPE>
class ComplexNetwork{

    private:
        typedef Node<NODE_TYPE, EDGE_TYPE>* NodePtr;
        typedef Edge<NODE_TYPE, EDGE_TYPE> * EdgePtr;
        typedef typename std::multimap< std::pair< NodePtr, NodePtr>, EdgePtr>::iterator edge_iterator;

        std::map<NODE_TYPE, NodePtr  > nodes;
        std::multimap< std::pair< NodePtr, NodePtr>, EdgePtr, 
            bool(*)(std::pair<NodePtr, NodePtr> , std::pair<NodePtr, NodePtr>) > edges;
        static bool compare(std::pair< NodePtr, NodePtr> a, std::pair< NodePtr, NodePtr> b);


    public:
        ComplexNetwork();
        virtual ~ComplexNetwork();
        void addNode(NodePtr);
        void addEdge(EdgePtr);
        EdgePtr getEdge(NodePtr, NodePtr);
        NodePtr getNode(NODE_TYPE);
        edge_iterator getEdgesFromNode_LowerBound(NodePtr n);
        edge_iterator getEdgesFromNode_UpperBound(NodePtr n);
        unsigned long int getNumNodes() const;
        unsigned long int getNumEdges() const;
        void save(const char *filename) const;


};


template <class NODE_TYPE, class EDGE_TYPE>
ComplexNetwork<NODE_TYPE,EDGE_TYPE>::ComplexNetwork():edges( ComplexNetwork<NODE_TYPE, EDGE_TYPE>::compare ){
    
}


template <class NODE_TYPE, class EDGE_TYPE>
void ComplexNetwork<NODE_TYPE,EDGE_TYPE>::addNode(NodePtr n){
    if (this->nodes.find(n->getAttribute()) == this->nodes.end())
        this->nodes[n->getAttribute()]=n;
    else 
        delete n;
}

template <class NODE_TYPE, class EDGE_TYPE>
void ComplexNetwork<NODE_TYPE,EDGE_TYPE>::addEdge(EdgePtr e){
    std::pair< std::pair<NodePtr, NodePtr>, EdgePtr > v;
    v.first = std::pair<NodePtr, NodePtr>(e->from, e->to);
    v.second = e;
    edges.insert(v);

}

template <class NODE_TYPE, class EDGE_TYPE>
ComplexNetwork<NODE_TYPE, EDGE_TYPE>::~ComplexNetwork(){
    std::for_each(this->edges.begin(), this->edges.end(), 
            []( std::pair< std::pair<NodePtr, NodePtr>,  EdgePtr > el ){
                delete el.second;
            });

    edges.clear();


    std::for_each(nodes.begin(), nodes.end(), 
            [](std::pair< NODE_TYPE, NodePtr> el){
                delete el.second;   
            });

    nodes.clear();
}


template <class NODE_TYPE, class EDGE_TYPE>
bool ComplexNetwork<NODE_TYPE, EDGE_TYPE>::compare(std::pair< NodePtr, NodePtr> a, std::pair< NodePtr, NodePtr> b){
    NodePtr a1 = a.first > a.second ? a.first : a.second;
    NodePtr a2 = a.first > a.second ? a.second : a.first;
    NodePtr b1 = b.first > b.second ? b.first : b.second;
    NodePtr b2 = b.first > b.second ? b.second : b.first;
    if(a2 == NULL || b2 == NULL)
        return b1>a1;

    if(b1 != a1)
       return b1>a1;
    return b2>a2;
}


template <class NODE_TYPE, class EDGE_TYPE>
Edge<NODE_TYPE, EDGE_TYPE>* ComplexNetwork<NODE_TYPE, EDGE_TYPE>::getEdge(NodePtr a, NodePtr b){
   auto e= edges.find(std::pair<NodePtr, NodePtr>(a, b));
   if(e != edges.end())
       return e->second;
   else 
       return NULL;
}


template <class NODE_TYPE, class EDGE_TYPE>
Node<NODE_TYPE, EDGE_TYPE>* ComplexNetwork<NODE_TYPE, EDGE_TYPE>::getNode(NODE_TYPE attribute){
   auto n = nodes.find(attribute);
   if(n != nodes.end())
       return n->second;
   else 
       return NULL;
}


template <class NODE_TYPE, class EDGE_TYPE>
typename ComplexNetwork<NODE_TYPE, EDGE_TYPE>::edge_iterator ComplexNetwork<NODE_TYPE, EDGE_TYPE>::getEdgesFromNode_LowerBound(NodePtr n){
    return edges.lower_bound( std::pair<NodePtr, NodePtr>(n, NULL) );
}

template <class NODE_TYPE, class EDGE_TYPE>
typename ComplexNetwork<NODE_TYPE, EDGE_TYPE>::edge_iterator ComplexNetwork<NODE_TYPE, EDGE_TYPE>::getEdgesFromNode_UpperBound(NodePtr n){
    return edges.upper_bound( std::pair<NodePtr, NodePtr>(n, NULL) );
}


template <class NODE_TYPE, class EDGE_TYPE>
unsigned long int ComplexNetwork<NODE_TYPE, EDGE_TYPE>::getNumNodes() const{
    return this->nodes.size();
}


template <class NODE_TYPE, class EDGE_TYPE>
unsigned long int ComplexNetwork<NODE_TYPE, EDGE_TYPE>::getNumEdges() const{
    return this->edges.size();
}


template <class NODE_TYPE, class EDGE_TYPE>
void ComplexNetwork<NODE_TYPE, EDGE_TYPE>::save(const char *filename) const{
    unsigned long int last_id = 0;
    std::map< NodePtr, unsigned long int> ids;
    FILE* f = fopen(filename, "wb");
    for(auto n=this->nodes.begin(); n != this->nodes.end(); n++){
        fwrite(n->second, sizeof(Node<NODE_TYPE, EDGE_TYPE>), 1, f);
        ids[n->second] = last_id++;
    }
    fclose(f);
}

#endif




