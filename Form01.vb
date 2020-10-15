Public Class Form01
    Private Sub btn_isPass_Click(sender As Object, e As EventArgs) Handles btn_isPass.Click
        Dim result As String
        Dim score As Integer = CInt(tb_score.Text)

        If score >= 95 Then
            result = "A+"
        ElseIf score >= 90 Then
            result = "A"
        ElseIf score >= 85 Then
            result = "B+"
        ElseIf score >= 80 Then
            result = "B"
        ElseIf score >= 75 Then
            result = "C+"
        ElseIf score >= 70 Then
            result = "C"
        ElseIf score >= 65 Then
            result = "D+"
        ElseIf score >= 60 Then
            result = "D"
        Else
            result = "F"
        End If

        MessageBox.Show(tb_name.Text & "님의 점수는 " & tb_score.Text & "입니다." & vbCrLf & "시험성적 : " & result)
        tb_score.SelectAll()
    End Sub

    Private Sub Form01_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        tb_name.Select()            '맨첨에 이름텍스트박스선택   문제1. 탭키누르면 순서가 이상함
        AcceptButton = btn_isPass   '버튼과 점수텍스트박스연동
    End Sub
End Class
