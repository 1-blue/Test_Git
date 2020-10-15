<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form04
    Inherits System.Windows.Forms.Form

    'Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
    <System.Diagnostics.DebuggerNonUserCode()> _
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
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.btn_for = New System.Windows.Forms.Button()
        Me.tb_for = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'btn_for
        '
        Me.btn_for.Location = New System.Drawing.Point(40, 117)
        Me.btn_for.Name = "btn_for"
        Me.btn_for.Size = New System.Drawing.Size(99, 34)
        Me.btn_for.TabIndex = 1
        Me.btn_for.Text = "반복계산"
        Me.btn_for.UseVisualStyleBackColor = True
        '
        'tb_for
        '
        Me.tb_for.Location = New System.Drawing.Point(54, 50)
        Me.tb_for.Name = "tb_for"
        Me.tb_for.Size = New System.Drawing.Size(71, 21)
        Me.tb_for.TabIndex = 2
        '
        'Form04
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(177, 208)
        Me.Controls.Add(Me.tb_for)
        Me.Controls.Add(Me.btn_for)
        Me.Name = "Form04"
        Me.Text = "Form04"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents btn_for As Button
    Friend WithEvents tb_for As TextBox
End Class
