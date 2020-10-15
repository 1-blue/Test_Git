Public Class Form05
    Private Sub Form05_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        AcceptButton = btn_start
        tb_value.Select()
    End Sub

    '0~입력한놈사이의 5의배수의 합구함
    Private Sub btn_start_Click(sender As Object, e As EventArgs) Handles btn_start.Click
        Dim sum As Integer = 0
        Dim var As Integer = CInt(tb_value.Text)

        For i = 0 To var Step 5
            sum += i
        Next

        tb_value.Text = CStr(sum)
        tb_value.SelectAll()
    End Sub
End Class