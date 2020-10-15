Public Class Form02
    Dim number As Integer

    Private Sub Form02_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        number = Rnd(1) * 100
        lb_answer.Text = "정답 : " & CStr(number)
        lb_answer.Visible = False
        lb_pass.Visible = False
        tb_answer.Select()
    End Sub

    Private Sub btn_isOK_Click(sender As Object, e As EventArgs) Handles btn_isOK.Click
        AcceptButton = btn_isOK
        Dim answer As Integer = CInt(tb_answer.Text)

        If answer = number Then
            lb_pass.Visible = True
        Else
            If answer > number Then
                lb_info.Text = "정답은 입력하신 숫자가 더 큽니다."
            Else
                lb_info.Text = "정답은 입력하신 숫자가 더 작습니다."
            End If
            tb_answer.SelectAll()
        End If
    End Sub

    Private Sub btn_showAnswer_Click(sender As Object, e As EventArgs) Handles btn_showAnswer.Click
        lb_answer.Visible = True
    End Sub
End Class