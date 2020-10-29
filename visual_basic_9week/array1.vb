Public Class array1

    Public arr() As Char = "aabcdefghijklmnopqrstuwxyz"

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        AcceptButton = btn_click
        If tb_input.Focus() Then
            tb_input.Text = "성공"
        End If
    End Sub

    Private Sub btn_click_Click(sender As Object, e As EventArgs) Handles btn_click.Click
        If tb_input.Text <> "" Then
            Dim index As Integer = CInt(tb_input.Text)

            lb_str.Text = CStr(arr(index))
        Else
            lb_str.Text = ""
        End If

        tb_input.Focus()
        tb_input.SelectAll()
    End Sub
End Class
