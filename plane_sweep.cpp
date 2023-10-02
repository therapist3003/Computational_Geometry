#include <bits/stdc++.h>
#define Dictionary RandomizedSearchTree
using namespace std;


class EventPoint{
    public:
        Point p; //Contains the event point (x,y)
        //handleTransition will be overriden
        virtual void handleTransition(Dictonary<Edge*>&, Dictionary<EventPoint*>&, List<EventPoint*>*) = 0;
};

class LeftEndpoint : public EventPoint{
    public:
        Edge e; //The line segment
        LeftEndpoint(Edge *);
        void handleTransition(Dictionary<Edge*>&, Dictionary<EventPoint*>&,List<EventPoint*>*);
}