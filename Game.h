#pragma once
#include <vector>
#include "Actor.h"
#include "SpriteComponent.h"
#include "Window.h"
#include "Renderer.h"
#include "Vector2.h"
#include "Astroid.h"
#include "EnemyChaser.h"
#include "Ship.h"

using std::vector;

class Game
{
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

private:
	Game() : isRunning(true), isUpdatingActors(false) {}

public:
	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);

	Renderer& getRenderer() { return renderer; }
	// Game specific
	vector<Astroid*>& getAstroids();
	vector<EnemyChaser*>& getEnemyChasers();
	void addAstroid(Astroid* astroid);
	void addEnemyChaser(EnemyChaser* chaser);
	void removeAstroid(Astroid* astroid);
	void removeEnemyChaser(EnemyChaser* chaser);

private:
	void processInput();
	void update(float dt);
	void render();

	bool isRunning;
	Window window;
	Renderer renderer;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;

	// Game specific
	Ship* ship;

	vector<Astroid*> astroids;
	float asteroidSpawnCounter = 0;

	vector<EnemyChaser*> enemyChasers;
	float enemyChaserSpawnCounter = 0;
};