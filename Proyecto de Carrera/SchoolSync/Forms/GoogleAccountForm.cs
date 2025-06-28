using Google.Apis.Auth.OAuth2;

namespace SchoolSync.Forms
{
    public partial class GoogleAccountForm : Form
    {
        UserCredential? userCredential;
        public GoogleAccountForm()
        {
            InitializeComponent();
        }

        private void GoogleAccountForm_Load(object? sender, EventArgs e)
        {
            UpdateTexts();
        }

        public void SendCredential(UserCredential userCredential)
        {
            this.userCredential = userCredential;
            UpdateLoginTexts();
        }

        public UserCredential GetCredential() => userCredential;

        private async void LoginControl_Clicked(object? sender, EventArgs e)
        {
            if (userCredential == null)
            {
                userCredential = await GoogleAPI.GoogleAuth();
                if (userCredential != null)
                {
                    MessageBox.Show("Inicio de sesión exitoso");
                    UpdateLoginTexts();
                }
                else
                {
                    MessageBox.Show("Inicio de sesión fallido");
                }
            }
            else
            {
                await GoogleAPI.RevokeCredentials(userCredential);
                userCredential = null;
                MessageBox.Show("Cierre de sesión exitoso");
                UpdateLoginTexts();
            }
        }

        private void UpdateLoginTexts()
        {
            if (userCredential == null)
            {
                LoginControl.Text = "Iniciar Sesión";
                LabelLoginDescription.Text = "Inicia sesión con tu cuenta de Google para sincronizar tus eventos";
                LabelLoginDescription.TextAlign = ContentAlignment.MiddleCenter;
                LabelLoginDescription.Location = new Point((ClientSize.Width - LabelLoginDescription.Width) / 2, LabelLoginDescription.Location.Y);
            }
            else
            {
                LoginControl.Text = "Cerrar Sesión";
                LabelLoginDescription.Text = "Has iniciado sesión con tu cuenta de Google";
                LabelLoginDescription.TextAlign = ContentAlignment.MiddleCenter;
                LabelLoginDescription.Location = new Point((ClientSize.Width - LabelLoginDescription.Width) / 2, LabelLoginDescription.Location.Y);
            }
        }

        private void UpdateTexts()
        {
            UpdateLoginTexts();
            label1.TextAlign = ContentAlignment.MiddleCenter;
            label1.Location = new Point((ClientSize.Width - label1.Width) / 2, label1.Location.Y);
            LoginControl.TextAlign = ContentAlignment.MiddleCenter;
            LoginControl.Location = new Point((ClientSize.Width - LoginControl.Width) / 2, LoginControl.Location.Y);
        }
    }
}
