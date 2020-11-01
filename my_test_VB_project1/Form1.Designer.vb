<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows Form 디자이너에 필요합니다.
    Private components As System.ComponentModel.IContainer

    '참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
    '수정하려면 Windows Form 디자이너를 사용하십시오.  
    '코드 편집기에서는 수정하지 마세요.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.lbox_test = New System.Windows.Forms.ListBox()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lbox_test
        '
        Me.lbox_test.FormattingEnabled = True
        Me.lbox_test.ItemHeight = 12
        Me.lbox_test.Location = New System.Drawing.Point(30, 21)
        Me.lbox_test.Name = "lbox_test"
        Me.lbox_test.Size = New System.Drawing.Size(243, 268)
        Me.lbox_test.TabIndex = 1
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(339, 21)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(93, 51)
        Me.Button2.TabIndex = 3
        Me.Button2.Text = "Button2"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(560, 333)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.lbox_test)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents lbox_test As ListBox
    Friend WithEvents Button2 As Button
End Class
