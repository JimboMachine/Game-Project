namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class������ܨ�����s����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoButton {
	public:
		void LoadBitmap();				//Ū���Ϥ�
		void ShowBitmap();				//��ܹϤ�
		void SetTopLeft();				//�]�w�y��

	private:
		CMovingBitmap button[1];		//���s�ϧ�
		int x[10];						//���sx�y��
		int y[10];						//���sy�y��
	};
}