namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class�������d��T����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class stageImformation {
	public:
		stageImformation();
		string getRivalBase(int stage);				//���o�����d�Ĥ誺��
		void   LoadBitmap();						//Ū���Ϥ�
		void   ShowBitmapBackGround(int stage);		//��ܭI���Ϥ�
		void   ShowBitmapName(int stage);			//������d�W�ٹϤ�
	private:
		static CMovingBitmap BackGround[10];			//�I��
		static CMovingBitmap Name[10];				//���d�W��
		string stageRivalBase[10] = { "Taiwan Base","Hong Kong Base","Thailand Base","China Base","Mongolia Base","Korea Base","Japan Base","Australia Base","Singapore Base","Maldives Base"};//�����d�Ĥ誺��
		bool isBmpLoaded;				// �O�_�w�g���J�ϧ�
	};
}