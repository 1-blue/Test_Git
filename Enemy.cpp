#include "Enemy.h"

Enemy::Enemy(CommonData* data, EffectManager* effectManager)
{
	commonData = data;
	this->effectManager = effectManager;
	Init();
}

void Enemy::Init()
{
	gameManager = new GameManager(commonData);
	srand((unsigned)time(NULL));

	isWall = false;

	SetShotAbleEnemy();

	//딜레이 시간과 이동방향 설정
	//moveDelay.SetDelayTime((1000 - ((commonData->GetStage() - 1) * 30)));
	cout << moveDelay.GetDelayTime() << endl;
	dir = 1;

	SetSpawnPos();
}

void Enemy::Move()
{
	if (moveDelay.CkEndDelay()) {
		if (isWall == false) {
			if (CkWall())
				isWall = true;
		}
		else
			isWall = false;

		if (dir > 0 && isWall == false) {
			for (int i = ENEMY_SIZE - 1; i >= 0; i--) {
				if (enemy[i].GetIsSurv()) {
					commonData->SetBoard(enemy[i].GetXPos(), enemy[i].GetYPos(), BLANK);
					enemy[i].SetXPos(enemy[i].GetXPos() + dir);
					commonData->SetBoard(enemy[i].GetXPos(), enemy[i].GetYPos(), enemy[i].GetEnemyScore());
				}
			}
		}
		else if (dir < 0 && isWall == false) {
			for (int i = 0; i < ENEMY_SIZE; i++) {
				if (enemy[i].GetIsSurv()) {
					commonData->SetBoard(enemy[i].GetXPos(), enemy[i].GetYPos(), BLANK);
					enemy[i].SetXPos(enemy[i].GetXPos() + dir);
					commonData->SetBoard(enemy[i].GetXPos(), enemy[i].GetYPos(), enemy[i].GetEnemyScore());
				}
			}
		}
		else {
			for (int i = ENEMY_SIZE - 1; i >= 0; i--) {
				if (enemy[i].GetIsSurv()) {
					commonData->SetBoard(enemy[i].GetXPos(), enemy[i].GetYPos(), BLANK);
					enemy[i].SetYPos(enemy[i].GetYPos() + 1);
					commonData->SetBoard(enemy[i].GetXPos(), enemy[i].GetYPos(), enemy[i].GetEnemyScore());
				}
			}
			moveDelay.SetDelayTime(moveDelay.GetDelayTime() - 20);
			dir *= -1;
		}
	}
}

void Enemy::ShotBulletMove()
{
	int temp;
	if (bullet.size() > 0) {
		for (auto iterator = bullet.begin(); iterator != bullet.end(); iterator++) {
			temp = (*iterator)->Move();
			switch (temp)
			{
			case WALL:		(*iterator)->SetSurv(false);
				break;
			case PLAYER:	(*iterator)->SetSurv(false);
				isPlayer = true;
				break;
			case SHIELD:	(*iterator)->SetSurv(false);
				commonData->SetBoard((*iterator)->GetXPos(), (*iterator)->GetYPos(), BLANK);
				break;
			}
		}
	}

	RemoveBullet();
}

int Enemy::CkWall()
{
	for (int i = 0; i < ENEMY_SIZE; i++) {
		if (enemy[i].GetIsSurv()) {
			if ((enemy[i].GetXPos() + 1) == (commonData->GetMapSizeX() - 1) || (enemy[i].GetXPos() - 1) == 0)
				return 1;	//벽 옆이면 1리턴
		}
	}
	return 0;//벽 X 0리턴
}

void Enemy::Shot()
{
	int count = 0;
	randomShotAbleIndex = rand() % 11; // 랜덤 인덱스 설정
	shotDelay.SetDelayTime((rand() % ((5000 - 1000) + 1) + 1000));
	if (shotDelay.CkEndDelay()) {
		for (auto i = shotAbleEnemy.begin(); i != shotAbleEnemy.end(); i++) {
			if (count == randomShotAbleIndex) {
				bullet.emplace_back(new Bullet(enemy[*i].GetXPos(), enemy[*i].GetYPos(), false, commonData));
				break;
			}
			count++;
		}
	}
}

void Enemy::RemoveBullet()
{
	for (auto iterator = bullet.begin(); iterator != bullet.end();) {
		if (!(*iterator)->GetSurv()) {
			delete(*iterator);
			bullet.erase(iterator++);
			bulletHit = false;
			break;
		}
		else
			iterator++;
	}
}

void Enemy::Hit(int x, int y)
{
	int index = 0;
	for (int i = 0; i < ENEMY_SIZE; i++) {
		if (enemy[i].GetIsSurv()) {
			if (enemy[i].GetXPos() == x && enemy[i].GetYPos() == y) {
				index = i;
				break;
			}
		}
	}

	enemy[index].SetIsSurv(false);
	commonData->SetCurrentScore(commonData->GetCurrentScore() + enemy[index].GetEnemyScore());

	Pos pos;

	pos.SetX(enemy[index].GetXPos());
	pos.SetY(enemy[index].GetYPos());
	effectManager->PrintHitEffect(pos);

	moveDelay.SetDelayTime(moveDelay.GetDelayTime() - ((ENEMY_SIZE - CkEnemyCount()) / 2));
	SetShotAbleEnemies();
}

bool Enemy::IsPlayertHit()
{
	if (isPlayer == true) {
		isPlayer = false;
		return true;
	}

	return false;
}

int Enemy::CkEnemyCount()
{
	int count = 0;
	for (int i = 0; i < ENEMY_SIZE; i++) {
		if (enemy[i].GetIsSurv())
			count++;
	}
	return count;
}

void Enemy::SetShotAbleEnemies()
{
	bool loop = true;				//샤격불가 = -1 / 그 이외엔 다음샤격가능 적 설정
	for (auto i = shotAbleEnemy.begin(); i != shotAbleEnemy.end(); i++) {
		if (!enemy[*i].GetIsSurv()) {
			while (loop) {
				if ((0 <= (*i - ENEMIES_IN_LINE))) {
					if (enemy[*i - ENEMIES_IN_LINE].GetIsSurv()) {
						*i = *i - ENEMIES_IN_LINE;
						loop = false;
					}
					else
						*i = *i - ENEMIES_IN_LINE;
				}
				else {
					*i = -1;
					loop = false;
				}
			}
		}
	}

	//만약 -1로 설정되었다면 그 값 삭제
	for (auto i = shotAbleEnemy.begin(); i != shotAbleEnemy.end();) {
		if (*i == -1)
			shotAbleEnemy.erase(i++);
		else
			i++;
	}
}

void Enemy::SetSpawnPos()
{
	int tempIndex = 0;

	//보드판 정보로 스폰위치 설정
	for (int y = 0; y < (commonData->GetMapSizeY() - 1); y++) {
		for (int x = 0; x < (commonData->GetMapSizeX() - 1); x++) {
			switch (commonData->GetBoard(x, y)) {
			case SQUID:
			case CRAB:
			case OCTOPUS:
				enemy[tempIndex].SetIsSurv(TRUE);
				enemy[tempIndex].SetXPos(x);
				enemy[tempIndex].SetYPos(y);
				enemy[tempIndex].SetEnemyScore(commonData->GetBoard(x, y));
				tempIndex++;
				break;
			default:
				break;
			}
		}
	}
}

void Enemy::SetShotAbleEnemy()
{
	shotAbleEnemy.clear();
	for (int i = (ENEMY_SIZE - 1); i > ((ENEMY_SIZE - 1) - ENEMIES_IN_LINE); i--)	//사격가능 적위치 설정
		shotAbleEnemy.emplace_back(i);		//발사 가능 적들 설정
}

void Enemy::ClearDynamicAlloc()
{
	for (auto i = bullet.begin(); i != bullet.end(); i++)
		delete(*i);

	bullet.clear();
	delete gameManager;
}
