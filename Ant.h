#ifndef ANT_H
#define ANT_H


class Ant{
        private:
                int x;
                int y;
  		int id_number;
		int experience;
                int MAX_X;
		int MAX_Y;
        public:
                Ant(int id);
		Ant(const Ant&);
                void move();
		int getMax_X(){return MAX_X;};
		int getMax_Y(){return MAX_Y;};
                int getID(){return id_number;};
                int getX(){return x;};
                int getY(){return y;};
		bool fight(Ant*);
		int getExperience(){return experience;};
		int setExperience(int exp){experience = exp;};
};

#endif
