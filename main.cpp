#include "DxLib.h"

#include "Game.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Window���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�B���h�[���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);


	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();

		DrawString(160, 160,"�e�X�g�I", GetColor(0, 255, 255));
		DrawString(160, 192, "�t�@�C���̍X�V�̃e�X�g", GetColor(255, 255, 255));

		// ����ʂ�\��ʂ����ւ���
		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}