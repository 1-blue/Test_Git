<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form01
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
        Me.lb_name = New System.Windows.Forms.Label()
        Me.tb_name = New System.Windows.Forms.TextBox()
        Me.lb_score = New System.Windows.Forms.Label()
        Me.tb_score = New System.Windows.Forms.TextBox()
        Me.btn_isPass = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lb_name
        '
        Me.lb_name.AutoSize = True
        Me.lb_name.Location = New System.Drawing.Point(48, 69)
        Me.lb_name.Name = "lb_name"
        Me.lb_name.Size = New System.Drawing.Size(29, 12)
        Me.lb_name.TabIndex = 0
        Me.lb_name.Text = "이름"
        '
        'tb_name
        '
        Me.tb_name.Location = New System.Drawing.Point(123, 60)
        Me.tb_name.Name = "tb_name"
        Me.tb_name.Size = New System.Drawing.Size(100, 21)
        Me.tb_name.TabIndex = 1
        '
        'lb_score
        '
        Me.lb_score.AutoSize = True
        Me.lb_score.Location = New System.Drawing.Point(48, 122)
        Me.lb_score.Name = "lb_score"
        Me.lb_score.Size = New System.Drawing.Size(29, 12)
        Me.lb_score.TabIndex = 0
        Me.lb_score.Text = "점수"
        '
        'tb_score
        '
        Me.tb_score.Location = New System.Drawing.Point(123, 113)
        Me.tb_score.Name = "tb_score"
        Me.tb_score.Size = New System.Drawing.Size(100, 21)
        Me.tb_score.TabIndex = 1
        '
        'btn_isPass
        '
        Me.btn_isPass.Location = New System.Drawing.Point(123, 193)
        Me.btn_isPass.Name = "btn_isPass"
        Me.btn_isPass.Size = New System.Drawing.Size(100, 40)
        Me.btn_isPass.TabIndex = 2
        Me.btn_isPass.Text = "결과발표"
        Me.btn_isPass.UseVisualStyleBackColor = True
        '
        'Form01
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(280, 298)
        Me.Controls.Add(Me.btn_isPass)
        Me.Controls.Add(Me.tb_score)
        Me.Controls.Add(Me.tb_name)
        Me.Controls.Add(Me.lb_score)
        Me.Controls.Add(Me.lb_name)
        Me.Name = "Form01"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lb_name As Label
    Friend WithEvents tb_name As TextBox
    Friend WithEvents lb_score As Label
    Friend WithEvents tb_score As TextBox
    Friend WithEvents btn_isPass As Button
End Class
