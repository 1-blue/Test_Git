Public Class Form06

    Private Sub Form06_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        tb_start.Select()
        tb_result.Enabled = False
    End Sub

    Private Sub btn_culculate_Click(sender As Object, e As EventArgs) Handles btn_culculate.Click
        Dim start As Integer = CInt(tb_start.Text)
        Dim endVar As Integer = CInt(tb_end.Text)
        Dim increase As Integer = CInt(tb_increase.Text)
        Dim sum As Integer = 0

        For i = start To endVar Step increase
            sum += i
        Next

        tb_result.Text = CStr(sum)
        tb_start.Focus()
        tb_start.SelectAll()
    End Sub

    Private Sub tb_increase_TextChanged(sender As Object, e As EventArgs) Handles tb_increase.TextChanged
        AcceptButton = btn_culculate
    End Sub
End Class