Public Class Form04
    Private Sub Form04_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        AcceptButton = btn_for
        tb_for.Select()
    End Sub

    Private Sub btn_for_Click(sender As Object, e As EventArgs) Handles btn_for.Click
        Dim sum As Integer = 0
        Dim num As Integer = CInt(tb_for.Text)

        For i = 0 To 9 Step 1
            sum = sum + num
        Next

        tb_for.Text = CStr(sum)
        tb_for.SelectAll()
    End Sub
End Class