namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class������ܨ�����s����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoButton {
	public:
		nekoButton();
		void LoadBitmap();				//Ū���Ϥ�
		void ShowBitmap();				//��ܹϤ�
		void SetTopLeft();				//�]�w�y��
		void SetIsClicked(bool clicked);//�]�w�O�_�Q���U
	private:
		static CMovingBitmap button[10];		//���s�ϧ�
		int xGap;						//���s�P���s������X���Z
		int yGap;						//���s�P���s������Y���Z
		bool isBmpLoaded;				// �O�_�w�g���J�ϧ�
		bool isClicked;					//���s�O�_�Q���U
	};
}