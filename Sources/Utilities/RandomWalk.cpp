#include "RandomWalk.hpp"

RandomWalk::RandomWalk()
{
}


void RandomWalk::normalizeGraph(FeaturesComplexNetwork &cn){
    FeaturesComplexNetwork::NodeIterator nodes;
    FeaturesComplexNetwork::EdgeIterator edges;
    for( nodes = cn.Begin(); nodes != cn.End(); nodes++){
        //sum weights
        float weight = 0;
        for( edges = nodes.EdgesBegin(); edges != nodes.EdgesEnd(); edges++ ){
            weight += edges->getWeight();
        }
        for( edges = nodes.EdgesBegin(); edges != nodes.EdgesEnd(); edges++ ){
            edges->setWeight(edges->getWeight()/weight);
        }
    }
}
