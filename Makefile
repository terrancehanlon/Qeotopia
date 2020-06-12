g = g++ -std=c++11 -c


exeName = mainp

sfmlFlags = -lsfml-graphics -lsfml-window -lsfml-system


link = target/Imports.o 	\
	target/Animation.o	\
	target/AnimatedSprite.o	\
	target/Movement.o \
	target/Health.o \
	target/Platform.o \
	target/Door.o \
	target/Zone.o \
	target/ZoneOne.o \
	target/Pig.o \
	target/HealthBar.o \
	target/Entity.o \
	target/ActiveState.o \
	target/Game.o	\
	target/Main.o

ent:
	$(g) core/entities/structural/Platform.cpp -o target/Platform.o 
	$(g) core/entities/UI/HealthBar.cpp -o target/HealthBar.o
	$(g) core/entities/structural/Door.cpp -o target/Door.o
	$(g) core/entities/alive/Pig.cpp -o target/Pig.o
	$(g) core/entities/alive/Entity.cpp -o target/Entity.o
	g++ $(link) -o $(exeName) $(sfmlFlags);

zone:
	$(g) core/zones/Zone.cpp -o target/Zone.o
	$(g) core/zones/ZoneOne.cpp -o target/ZoneOne.o
	g++ $(link) -o $(exeName) $(sfmlFlags);

states:
	$(g) core/states/ActiveState.cpp -o target/ActiveState.o
	g++ $(link) -o $(exeName) $(sfmlFlags);

comps:
	$(g) core/components/Movement.cpp -o target/Movement.o
	$(g) core/components/Health.cpp -o target/Health.o 
	g++ $(link) -o $(exeName) $(sfmlFlags);


all:
	$(g) Lib/Imports.cpp -o target/Imports.o
	$(g) Lib/Animation.cpp -o target/Animation.o
	$(g) Lib/AnimatedSprite.cpp -o target/AnimatedSprite.o
	$(g) core/components/Health.cpp -o target/Health.o 
	$(g) core/entities/structural/Platform.cpp -o target/Platform.o 
	$(g) core/entities/UI/HealthBar.cpp -o target/HealthBar.o
	$(g) core/entities/structural/Door.cpp -o target/Door.o
	$(g) core/zones/Zone.cpp -o target/Zone.o
	$(g) core/zones/ZoneOne.cpp -o target/ZoneOne.o
	$(g) core/components/Movement.cpp -o target/Movement.o
	$(g) core/entities/alive/Pig.cpp -o target/Pig.o
	$(g) core/entities/alive/Entity.cpp -o target/Entity.o
	$(g) core/states/ActiveState.cpp -o target/ActiveState.o
	$(g) core/Game.cpp -o target/Game.o
	$(g) main.cpp -o target/Main.o
	g++ $(link) -o $(exeName) $(sfmlFlags);

clean:
	rm -rf target/*