#pragma once
#include "roll.h"
#include "character.h"

class battle {
public:

	int dmg; // �ˮ`��
	roll character;
	roll enemy;

	// ����:��J�ˮ`�[�ȡB�ˮ`��B���޵��šB�O�_���F��X�ˮ`
	void attack(Player attacker, Player defender, bool pierce) {

		// �H�����⪺���޻P�ĤH���������\��
		srand(time(NULL));
		character.check(attacker.get_skill().Brawl);
		enemy.check(defender.get_skill().Brawl);

		// �p�⨤��ˮ`�[��
		if (attacker.get_ability().DB <= 0) {
			db = attacker.get_ability().DB;
		}
		else {
			db = rand() % attacker.get_ability().DB + 1;
		}

		// �������P���ު�����˩w
		// �������\
		if (character.success >= enemy.success) {
			atk_success = true;

			// �P�_���\�{��
			if (character.success == 0) {
				dmg = 0;
			}
			else if (character.success == 1 || character.success == 2) {
				dmg = rand() % attacker.get_ability().DMG + 1 + db;
			}
			else {

				// �P�_���ˮ`
				if (pierce) {
					dmg = rand() % attacker.get_ability().DMG + 1 + attacker.get_ability().DMG + attacker.get_ability().DB;
				}
				else {
					dmg = attacker.get_ability().DMG + attacker.get_ability().DB;
				}
			}
		}
		// �������\
		else {
			atk_success = false;
			dmg = rand() % defender.get_ability().DB + 1;
		}
	}

	// �{��:��J�{�׵��šB�ĤH���޵��šB�ĤH�ˮ`��F�ĤH�ˮ`�[��
	int evade(Player attacker, Player defender) {
		// �H�����⪺�{�׻P�ĤH�����ަ��\��
		srand(time(NULL));
		character.check(defender.get_skill().Evade);
		enemy.check(attacker.get_skill().Brawl);

		// ���{�׻P���ު�����˩w
		if (character.success >= enemy.success) {
			atk_success = false;
		}
		else {
			atk_success = true;

			// �p�⨤��ˮ`�[��
			if (attacker.get_ability().DB <= 0) {
				db = attacker.get_ability().DB;
			}
			else {
				db = rand() % attacker.get_ability().DB + 1;
			}

			// �P�_���\�{��
			if (enemy.success == 0) {
				dmg = 0;
			}
			else if (enemy.success == 1 || enemy.success == 2) {
				dmg = rand() % attacker.get_ability().DMG + 1 + db;
			}
			else {
				dmg = attacker.get_ability().DMG + attacker.get_ability().DB;
			}
		}
	}

	// ����:��J���޵��šB����ˮ`��B�ĤH���޵��šB�ĤH�ˮ`��F�ĤH�ˮ`�[��
	int Evade(Player attacker, Player defender) {
		// �H�����⪺�{�׻P�ĤH�����ަ��\��
		srand(time(NULL));
		character.check(defender.get_skill().Brawl);
		enemy.check(attacker.get_skill().Brawl);

		// �������P���ު�����˩w
		if (character.success > enemy.success) {
			atk_success = false;
			dmg = rand() % defender.get_ability().DMG + 1;
		}
		else {
			atk_success = true;

			// �p��ĤH�ˮ`�[��
			if (attacker.get_ability().DB <= 0) {
				db = attacker.get_ability().DB;
			}
			else {
				db = rand() % attacker.get_ability().DB + 1;
			}

			// �P�_���\�{��
			if (enemy.success == 0) {
				dmg = 0;
			}
			else if (enemy.success == 1 || enemy.success == 2) {
				dmg = rand() % attacker.get_ability().DMG + 1 + db;
			}
			else {
				dmg = attacker.get_ability().DMG + attacker.get_ability().DB;
			}
		}
	}

private:
	bool atk_success; // �����O�_���\
	int db; // DB�H�����G

};