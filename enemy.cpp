#include "enemy.h"

void enemy::initShape() {
	this->lection1.loadFromFile("textures/texture1.png");
	this->laba.loadFromFile("textures/laba.png");
	this->letuchka.loadFromFile("textures/letuchka.png");
	this->coffee.loadFromFile("textures/coffee.png");
	this->ChatGPT.loadFromFile("textures/GPT.png");
}

void enemy::initVar() {
	type = rand()%11;
	if (type == 0 or type == 2 or type == 4 or type == 6 or type == 8){ //���� ���� ������������ switch case, ��, � ���� ���� ��������� ����� �� ������
	this->spid = 8.f;
	this->hp = 10;
	this->hpMAX = 10;
	this->damage = 0.f;
	this->points = 10;
	this->shape.setTexture(this->lection1);
	this->shape.setScale(0.1f, 0.1f);
	}
	else if (type == 3 or type == 7 or type == 9){
	this->spid = 5.f;
	this->hp = 20;
	this->hpMAX = 20;
	this->damage = 0.f;
	this->points = 25;
	this->shape.setTexture(this->laba);
	this->shape.setScale(2.f, 2.f);
	}
	else if(type == 1 or type == 5){
	this->spid = 7.f;
	this->hp = 30;
	this->hpMAX = 30;
	this->damage = 0.f;
	this->points = 50;
	this->shape.setTexture(this->letuchka);
	this->shape.setScale(0.1f, 0.1f);
	}
	/*else if (type == 10) {
		this->spid = 5.f;
		this->hp = 1;
		this->hpMAX = 1;
		this->damage = 0.f;
		this->points = 0;

		a_type = rand() % 2;
		if (a_type == 1) {
			this->spid = 5.f;
			this->hp = 1;
			this->hpMAX = 1;
			this->damage = 0.f;
			this->points = 0;
			this->shape.setTexture(coffee);
			this->shape.setScale(0.15f, 0.15f);
		}
		else if (a_type == 0) {
			this->spid = 5.f;
			this->hp = 1;
			this->hpMAX = 1;
			this->damage = 0.f;
			this->points = 0;
			this->shape.setTexture(ChatGPT);
			this->shape.setScale(0.5f, 0.5f);
		}
	}*/
}

enemy::enemy(float pX, float pY) {
	this->initShape();
	this->initVar();
	this->shape.setPosition(pX, pY);
	
}
enemy::~enemy() {

}

const FloatRect enemy::getBounds_e() const {
	return this->shape.getGlobalBounds();
}

const int& enemy::getPoints() const
{
	return this->points;
}

float enemy::getDamage()
{
	return this->damage;
}

/*void enemy::isLectionAttended() //is useless now
{
	this->shape.setTexture(this->lection2);
}*/

int enemy::getType()
{
	return type;
}

int enemy::getTypeAGAIN()
{
	return a_type;
}

int enemy::getHP()
{
	return hp;
}

void enemy::eraseHP(int damage)
{
	this->hp = hp - damage;
}

void enemy::upd_enem() {
	this->shape.move(0.f, this->spid);
}

void enemy::render_enemy(RenderTarget* target) {
	target->draw(this->shape);
}
