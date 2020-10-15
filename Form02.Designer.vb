<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form02
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
        Me.lb_info = New System.Windows.Forms.Label()
        Me.lb_answer = New System.Windows.Forms.Label()
        Me.lb_pass = New System.Windows.Forms.Label()
        Me.tb_answer = New System.Windows.Forms.TextBox()
        Me.btn_showAnswer = New System.Windows.Forms.Button()
        Me.btn_isOK = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lb_info
        '
        Me.lb_info.AutoSize = True
        Me.lb_info.Location = New System.Drawing.Point(37, 29)
        Me.lb_info.Name = "lb_info"
        Me.lb_info.Size = New System.Drawing.Size(148, 12)
        Me.lb_info.TabIndex = 0
        Me.lb_info.Text = "정답을 입력하세요(1~100)"
        '
        'lb_answer
        '
        Me.lb_answer.AutoSize = True
        Me.lb_answer.Location = New System.Drawing.Point(37, 146)
        Me.lb_answer.Name = "lb_answer"
        Me.lb_answer.Size = New System.Drawing.Size(53, 12)
        Me.lb_answer.TabIndex = 0
        Me.lb_answer.Text = "정답보기"
        '
        'lb_pass
        '
        Me.lb_pass.AutoSize = True
        Me.lb_pass.Location = New System.Drawing.Point(37, 186)
        Me.lb_pass.Name = "lb_pass"
        Me.lb_pass.Size = New System.Drawing.Size(29, 12)
        Me.lb_pass.TabIndex = 0
        Me.lb_pass.Text = "정답"
        '
        'tb_answer
        '
        Me.tb_answer.Location = New System.Drawing.Point(39, 62)
        Me.tb_answer.Name = "tb_answer"
        Me.tb_answer.Size = New System.Drawing.Size(100, 21)
        Me.tb_answer.TabIndex = 1
        '
        'btn_showAnswer
        '
        Me.btn_showAnswer.Location = New System.Drawing.Point(208, 62)
        Me.btn_showAnswer.Name = "btn_showAnswer"
        Me.btn_showAnswer.Size = New System.Drawing.Size(75, 23)
        Me.btn_showAnswer.TabIndex = 2
        Me.btn_showAnswer.Text = "정답보기"
        Me.btn_showAnswer.UseVisualStyleBackColor = True
        '
        'btn_isOK
        '
        Me.btn_isOK.Location = New System.Drawing.Point(208, 112)
        Me.btn_isOK.Name = "btn_isOK"
        Me.btn_isOK.Size = New System.Drawing.Size(75, 23)
        Me.btn_isOK.TabIndex = 2
        Me.btn_isOK.Text = "확인"
        Me.btn_isOK.UseVisualStyleBackColor = True
        '
        'Form02
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(311, 282)
        Me.Controls.Add(Me.btn_isOK)
        Me.Controls.Add(Me.btn_showAnswer)
        Me.Controls.Add(Me.tb_answer)
        Me.Controls.Add(Me.lb_pass)
        Me.Controls.Add(Me.lb_answer)
        Me.Controls.Add(Me.lb_info)
        Me.Name = "Form02"
        Me.Text = "Form02"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lb_info As Label
    Friend WithEvents lb_answer As Label
    Friend WithEvents lb_pass As Label
    Friend WithEvents tb_answer As TextBox
    Friend WithEvents btn_showAnswer As Button
    Friend WithEvents btn_isOK As Button
End Class
