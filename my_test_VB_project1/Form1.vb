Public Class Form1
    Private arr(2) As String
    Private x As Integer = 1

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        For i = 0 To x * 2
            ReDim arr(x * 2)
            arr(i) = i
        Next

        For i = 0 To x * 2
            lbox_test.Items.Add(CStr(i))
        Next
        x += 1
    End Sub
End Class
